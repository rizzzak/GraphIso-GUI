#include "RWMethod.h"
int RWMethod::Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP)
{
    if (solutionsFound || isNoMorePossibleCombinations || iterationLimitExceed)
        return 1;
    int quality, minF, newF, index, smallSize = smallGraph.size(), bigSize = bigGraph.size();
    std::vector<int> currentSwap, shortPerestanovka, qualities, oldPerestanovka = p;
    std::vector<std::vector<int>> allSwaps, newGraph;
    int startQ = compareTables(bigGraph, smallGraph, smallGraph.size());
    for (int i = 0; i < bigSize - 1; i++)
    {
        for (int j = i + 1; j < bigSize; j++)
        {
            std::swap(p[i], p[j]);
            for (int k = 0; k < smallSize; k++)
                shortPerestanovka.push_back(p[k]);
            newGraph = buildGraphFromP(shortPerestanovka, bigGraph);
            quality = compareTables(newGraph, smallGraph, smallSize);
            qualities.push_back(quality);
            p = oldPerestanovka;
            currentSwap.push_back(i);
            currentSwap.push_back(j);
            allSwaps.push_back(currentSwap);
            currentSwap.clear();
            shortPerestanovka.clear();
        }
    }
    double rk = (rand() % 10000) / 10000.;
    minF = 9999;
    index = -1;
    for (int i = 0; i < qualities.size(); i++)
    {
        rk = (rand() % 10000) / 10000.;
        newF = (qualities[i] - startQ) * (1 + 2 * d * (rk - 0.5));
        if (newF < minF)
        {
            std::vector<int> perestanovkaTest = p;
            std::swap(perestanovkaTest[allSwaps[i][0]], perestanovkaTest[allSwaps[i][1]]);
            if (find(checkedP.begin(), checkedP.end(), perestanovkaTest) == checkedP.end())
            {
                minF = newF;
                index = i;
            }
        }
    }
    if (index == -1)
    {
        isNoMorePossibleCombinations = true;
        localQ = smallSize * smallSize;
    }
    else
    {
        currentSwap = allSwaps[index];
        std::swap(p[allSwaps[index][0]], p[allSwaps[index][1]]);
        checkedP.push_back(p);
        localQ = qualities[index];
    }
    (*iterationCounter) += ((bigSize * (bigSize - 1)) / 2); //за одну итерацию проверяется путей на половину таблицы
    this->MethodBase::iterationFinalization(bigGraph, smallGraph, isoMatr, isoP);
    return 0;
}
int RWMethod::Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, int& metaMinQ) {
    if (solutionsFound || isNoMorePossibleCombinations || iterationLimitExceed)
        return 1;
    int quality, minF, newF, index, smallSize = smallGraph.size(), bigSize = bigGraph.size();
    std::vector<int> currentSwap, shortPerestanovka, qualities, oldPerestanovka = p;
    std::vector<std::vector<int>> allSwaps, newGraph;
    int startQ = compareTables(bigGraph, smallGraph, smallGraph.size());
    for (int i = 0; i < bigSize - 1; i++)
    {
        for (int j = i + 1; j < bigSize; j++)
        {
            std::swap(p[i], p[j]);
            for (int k = 0; k < smallSize; k++)
                shortPerestanovka.push_back(p[k]);
            newGraph = buildGraphFromP(shortPerestanovka, bigGraph);
            quality = compareTables(newGraph, smallGraph, smallSize);
            qualities.push_back(quality);
            p = oldPerestanovka;
            currentSwap.push_back(i);
            currentSwap.push_back(j);
            allSwaps.push_back(currentSwap);
            currentSwap.clear();
            shortPerestanovka.clear();
        }
    }
    double rk = (rand() % 10000) / 10000.;
    minF = 9999;
    index = -1;
    for (int i = 0; i < qualities.size(); i++)
    {
        rk = (rand() % 10000) / 10000.;
        newF = (qualities[i] - startQ) * (1 + 2 * d * (rk - 0.5));
        if (newF < minF)
        {
            std::vector<int> perestanovkaTest = p;
            std::swap(perestanovkaTest[allSwaps[i][0]], perestanovkaTest[allSwaps[i][1]]);
            if (find(checkedP.begin(), checkedP.end(), perestanovkaTest) == checkedP.end())
            {
                minF = newF;
                index = i;
            }
        }
    }
    if (index == -1)
    {
        isNoMorePossibleCombinations = true;
        localQ = smallSize * smallSize;
    }
    else
    {
        currentSwap = allSwaps[index];
        std::swap(p[allSwaps[index][0]], p[allSwaps[index][1]]);
        checkedP.push_back(p);
        localQ = qualities[index];
    }
    (*iterationCounter) += ((bigSize * (bigSize - 1)) / 2); //за одну итерацию проверяется путей на половину таблицы
    this->MethodBase::iterationFinalization(bigGraph, smallGraph, metaMinQ);
    return 0;
}
void RWMethod::Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit)
{
    this->MethodBase::Init(smallSize, bigSize, _goal, iterationCounter2, _iterationLimit);
    isNoMorePossibleCombinations = false;
    checkedP.clear();
}
std::vector<double> RWMethod::meta(std::vector<std::vector<std::vector<int>> >& sampleGraphBigMeta,
    std::vector<std::vector<std::vector<int>> >& sampleGraphSmallMeta, int _iterationLimit, double& param_val_init, double& param_val_step, int parameterToOptimize)
{
    std::vector<double> sigs; // 1 sig = 1 param_val
    param_val_init = 0.;
    param_val_step = 0.05;
    for (d = param_val_init; d < 1.01; d += param_val_step)
    {
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

    d = bestSigIndex * param_val_step;

    return sigs;
}
void RWMethod::setParameter(int parameterNumber, double value)
{
    if (parameterNumber == 0)
        d = value;
}