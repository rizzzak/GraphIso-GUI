#include "SAMethod.h"
int SAMethod::Iteration(std::vector<std::vector<int>>& graphBig, std::vector<std::vector<int>>& graphSmall, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP) {
    if (solutionsFound || iterationLimitExceed || isStucked)
        return 1;
    int bigSize = graphBig.size();
    int smallSize = graphSmall.size();
    std::vector<int> shortPerestanovka;
    int localQOld = localQ;
    std::vector<int> pOld = p;
    int i = 1, j = 1, k = 0;
    while (true)
    {
        while (i == j)
        {
            i = rand() % bigSize;
            j = rand() % bigSize;
        }
        std::swap(p[i], p[j]);
        if (std::find(checkedP.begin(), checkedP.end(), p) == checkedP.end())
            break;
        k++;
        if (k > 1000) //если тысячу раз не получилось найти новый путь ->
        {
            isStucked = true;
            break;
        }
    }
    checkedP.push_back(p);
    for (int k = 0; k < smallSize; k++)
        shortPerestanovka.push_back(p[k]);
    std::vector<std::vector<int>> newGraph = buildGraphFromP(shortPerestanovka, graphBig);
    localQ = compareTables(newGraph, graphSmall, smallSize);
    //мутация - случайный свап? вброс вершины вне мелкого графа в него на место случайной вершины?
    if (localQ > localQOld)
    {
        if (localQ > 0)
        {
            double f = exp(-1 * localQ / T);
            double rk = rand() / (double)RAND_MAX;
            if (rk > f)
                p = pOld;
        }
    }
    // охлаждение()
    T *= Gamma;
    (*iterationCounter)++;
    this->MethodBase::iterationFinalization(graphBig, graphSmall, isoMatr, isoP);
    return 0;
}
int SAMethod::Iteration(std::vector<std::vector<int>>& graphBig, std::vector<std::vector<int>>& graphSmall, int& metaMinQ) {
    if (solutionsFound || iterationLimitExceed || isStucked)
        return 1;

    int bigSize = graphBig.size();
    int smallSize = graphSmall.size();
    std::vector<int> shortPerestanovka;
    int localQOld = localQ;
    std::vector<int> pOld = p;
    int i = 1, j = 1, k = 0;
    while (true)
    {
        while (i == j)
        {
            i = rand() % bigSize;
            j = rand() % bigSize;
        }
        std::swap(p[i], p[j]);
        if (std::find(checkedP.begin(), checkedP.end(), p) == checkedP.end())
            break;
        k++;
        if (k > 1000) //если тысячу раз не получилось найти новый путь ->
        {
            isStucked = true;
            break;
        }
    }
    for (int k = 0; k < smallSize; k++)
        shortPerestanovka.push_back(p[k]);
    std::vector<std::vector<int>> newGraph = buildGraphFromP(shortPerestanovka, graphBig);
    localQ = compareTables(newGraph, graphSmall, smallSize);
    //мутация - случайный свап? вброс вершины вне мелкого графа в него на место случайной вершины?
    if (localQ >= localQOld)
    {
        if (localQ > 0)
        {
            double f = exp(-1 * localQ / T);
            double rk = rand() / (double)RAND_MAX;
            if (rk > f)
                p = pOld;
        }
    }
    // охлаждение()
    T *= Gamma;
    (*iterationCounter)++;
    this->MethodBase::iterationFinalization(graphBig, graphSmall, metaMinQ);
    return 0;
}
void SAMethod::Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit)
{
    isStucked = false;
    checkedP.clear();
    this->MethodBase::Init(smallSize, bigSize, _goal, iterationCounter2, _iterationLimit);
}
std::vector<double> SAMethod::meta(std::vector<std::vector<std::vector<int>> >& sampleGraphBigMeta,
    std::vector<std::vector<std::vector<int>> >& sampleGraphSmallMeta,
    int _iterationLimit, double& param_val_init, double& param_val_step, std::vector<double>& out_prob, int parameterToOptimize)
{
    std::vector<double> sigs;
    double param_val_end;
    if (parameterToOptimize == 0)
    {
        param_val_step = 100;
        param_val_init = 100;
        param_val_end = 1000;
    }
    else if (parameterToOptimize == 1)
    {
        param_val_step = 0.05;
        param_val_init = 0.05;
        param_val_end = 1.0;
    }
    for (double param = param_val_init; param < param_val_end; param += param_val_step)
    {
        int TEMPISOCNTR = 0;
        setParameter(parameterToOptimize, param);
        double averageSig = 0;
        for (int i = 0; i < sampleGraphBigMeta.size(); i++)
        {
            double sigCurrent = 0;
            std::vector<std::vector<int>> graphBig = sampleGraphBigMeta[i];
            std::vector<std::vector<int>> graphSmall = sampleGraphSmallMeta[i];
            int bigSize = graphBig.size();
            int smallSize = graphSmall.size();
            int metaIterationCounter = 0;
            int metaMinQ = smallSize * smallSize;
            Init(smallSize, bigSize, 1, &metaIterationCounter, _iterationLimit);
            while (!Iteration(graphBig, graphSmall, metaMinQ)) {}
            if (metaMinQ == 0)
            {
                TEMPISOCNTR++;
                //sig += 1;
                sigCurrent += 1;
                sigCurrent = sigCurrent + (1 - metaIterationCounter / _iterationLimit) / 2; // sig += 0..0.5 ~ 1/w(metaIterCntr)
            }
            else
            {
                sigCurrent = sigCurrent + (1 - metaIterationCounter / _iterationLimit) / 2;
                sigCurrent = sigCurrent + (1 - metaMinQ / (smallSize * smallSize)) / 4; //sig += 0..0.25 ~ 1/w(minQ)
            }
            averageSig += sigCurrent;
        }
        out_prob.push_back((double)TEMPISOCNTR / sampleGraphBigMeta.size());
        averageSig /= sampleGraphBigMeta.size();
        sigs.push_back(averageSig);
    }
    int bestSigIndex = 0;
    double maxSig = 0.;
    for (int i = 0; i < sigs.size(); i++)
    {
        if (sigs[i] > maxSig)
        {
            maxSig = sigs[i];
            bestSigIndex = i;
        }
    }
    setParameter(parameterToOptimize, param_val_init + bestSigIndex * param_val_step);    
    return sigs;
}
void SAMethod::setParameter(int parameterNumber, double value)
{
    if (parameterNumber == 0)
        T = value;
    else if (parameterNumber == 1)
        Gamma = value;
}
double SAMethod::getParameter(int parameterNumber)
{
    if (parameterNumber == 0)
        return T;
    else if (parameterNumber == 1)
        return Gamma;
}