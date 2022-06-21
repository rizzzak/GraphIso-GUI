#include "MethodBase.h"
void MethodBase::Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit) {
    std::vector<int> perestanovka;
    localMinQ = smallSize * smallSize;
    for (int i = 0; i < bigSize; i++)
    {
        perestanovka.push_back(i);
    }
    p = perestanovka;
    localProbability = 0.;
    pSolutions.clear();
    isomorphsFoundCounter = 0;
    isomorphsFoundGoal = _goal;
    averageQ = 0.;
    probability = 0.;
    dispersion = 0.;
    sigma = 0.;
    deltaQ = 0.;
    localQ = 0.;
    solutionsFound = false;
    iterationCounter = iterationCounter2;
    iterationLimit = _iterationLimit;
    iterationLimitExceed = false;
}
double MethodBase::getAverageQ()
{
    return averageQ;
}
double MethodBase::getProbability()
{
    return probability;
}
double MethodBase::getDispersion()
{
    return dispersion;
}
double MethodBase::getSigma()
{
    return sigma;
}
double MethodBase::getDeltaQ()
{
    return deltaQ;
}
void MethodBase::FindLocalStats()
{
    if (solutionsFound)
    {
        vector_Q.push_back(0);
    }
    else
    {
        vector_Q.push_back(localMinQ);
    }
}
void MethodBase::FindGlobalStats(int sizeOfSample)
{
    for (int i = 0; i < vector_Q.size(); i++)
    {
        averageQ += vector_Q[i];
        if (vector_Q[i] == 0)
            probability += 1.0;
    }
    probability /= sizeOfSample;
    averageQ /= sizeOfSample;
    for (int i = 0; i < vector_Q.size(); i++)
    {
        dispersion += pow((vector_Q[i] - averageQ), 2);
    }
    dispersion /= sizeOfSample;
    sigma = sqrt(dispersion);
    deltaQ = 1.96 * sigma / sqrt(sizeOfSample);
}
void MethodBase::ClearingTotal()
{
    vector_Q.clear();
    probability = 0;
    averageQ = 0;
    dispersion = 0;
}
int MethodBase::compareTables(std::vector<std::vector<int>> table, std::vector<std::vector<int>> table2, int n)
{
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] != table2[i][j])
                q++;
        }
    }
    return q;
}
std::vector<std::vector<int>> MethodBase::buildGraphFromP(std::vector<int> p, std::vector<std::vector<int>> source)
{
    std::vector<std::vector<int>> graph;
    std::vector<int> graphVertix;
    for (int i = 0; i < p.size(); i++)
    {
        graphVertix.push_back(0);
    }
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < p.size(); j++)
        {
            graphVertix[j] = source[p[i]][p[j]];
        }
        graph.push_back(graphVertix);
    }
    return graph;
}
std::vector<std::vector<int>> MethodBase::genGraphWithDensity(int n, double D)
{
    std::vector<std::vector<int>> newGraph;
    for (int i = 0; i < n; i++)
    {
        newGraph.push_back({});
        for (int j = 0; j < n; j++)
        {
            newGraph[i].push_back(0);
        }
    }
    double stepDPerEdge = 2. / (n * n - n);
    int edgesCnt = 0;
    for (int k = 0; k < ((n * n - n) / 2.) + 1.0; k++)
    {
        if (k != 0)
        {
            if ((D > k * stepDPerEdge - epsilon - stepDPerEdge / 2) && (D <= k * stepDPerEdge + epsilon + stepDPerEdge / 2))
            {
                edgesCnt = k;
                break;
            }
        }
        else
        {
            if (D <= stepDPerEdge / 2)
            {
                edgesCnt = k;
                break;
            }
        }
    }
    int randomVertix1;
    int randomVertix2;
    for (int i = 0; i < edgesCnt; i++)
    {
        while (true)
        {
            randomVertix1 = rand() % n;
            randomVertix2 = rand() % n;
            if (randomVertix1 == randomVertix2)
                continue;
            if (newGraph[randomVertix1][randomVertix2] == 0)
            {
                newGraph[randomVertix1][randomVertix2] = 1;
                newGraph[randomVertix2][randomVertix1] = 1;
                break;
            }
        }
    }
    return newGraph;
}
std::string MethodBase::getVectorInt(std::vector<int> vec, std::string name)
{
    std::string ret = "";
    for (int i = 0; i < vec.size(); i++)
        ret = ret + std::to_string(vec[i]) + " ";
    return ret;
}
void MethodBase::iterationFinalization(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP)
{
    (*iterationCounter)++;
    if ((*iterationCounter) > iterationLimit)
        iterationLimitExceed = true;
    if (localMinQ > localQ)
        localMinQ = localQ;

    if (localQ == 0)
    {
        //протоколирование перестановок-изоморфов
        std::vector<int> shortPerestanovka;
        for (int i = 0; i < smallGraph.size(); i++)
        {
            shortPerestanovka.push_back(p[i]);
        }
        if (find(pSolutions.begin(), pSolutions.end(), shortPerestanovka) == pSolutions.end())
        {
            isomorphsFoundCounter++;
            pSolutions.push_back(shortPerestanovka);
            isoMatr = buildGraphFromP(shortPerestanovka, bigGraph);
            isoP = shortPerestanovka;
        }

        //проверка условия окончания работы метода
        if (isomorphsFoundCounter == isomorphsFoundGoal)
            solutionsFound = true;
    }
}
void MethodBase::iterationFinalization(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, int& metaMinQ)
{
    (*iterationCounter)++;
    if ((*iterationCounter) > iterationLimit)
        iterationLimitExceed = true;
    if (metaMinQ > localQ)
        metaMinQ = localQ;
    if (localQ == 0)
    {
        isomorphsFoundCounter++;
        if (isomorphsFoundCounter == isomorphsFoundGoal)
            solutionsFound = true;
    }
}