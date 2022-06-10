#pragma once
#include "MethodBase.h"
#include <vector>
class GreedMethod :
    public MethodBase
{
public:
    virtual int Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP)
    {
        if (solutionsFound || noMorePossibleCombinations || iterationLimitExceed)
            return 1;
        int smallSize = smallGraph.size();
        int bigSize = bigGraph.size();
        int quality;
        int bestQuality, bestDeltaQuality(smallSize * smallSize), newDeltaQuality;
        int startQ = compareTables(bigGraph, smallGraph, smallGraph.size());;
        std::vector<int> bestPerestanovka = p;
        std::vector<int> oldPerestanovka = p;
        std::vector<int> shortPerestanovka;
        std::vector<std::vector<int>> newGraph;
        bestQuality = startQ;
        for (int i = 0; i < bigSize - 1; i++)
        {
            for (int j = i + 1; j < bigSize; j++)
            {
                std::swap(p[i], p[j]);
                for (int k = 0; k < smallSize; k++)
                    shortPerestanovka.push_back(p[k]);
                newGraph = buildGraphFromP(shortPerestanovka, bigGraph);
                quality = compareTables(newGraph, smallGraph, smallSize);
                newDeltaQuality = quality - startQ;
                if (newDeltaQuality < bestDeltaQuality)
                {
                    //проверка на использование полученной "хорошей" перестановки в прошлых итерациях
                    if (find(checkedP.begin(), checkedP.end(), p) == checkedP.end())
                    {
                        bestDeltaQuality = newDeltaQuality;
                        bestPerestanovka = p;
                        bestQuality = quality;
                    }
                }
                p = oldPerestanovka;
                shortPerestanovka.clear();
            }
        }
        if (bestDeltaQuality == smallSize * smallSize)
            noMorePossibleCombinations = true;
        p = bestPerestanovka;
        if (p.size() == 0)
            localQ = bestQuality;
        checkedP.push_back(p);
        localQ = bestQuality;
        (*iterationCounter) += ((bigSize * (bigSize - 1)) / 2); //за одну итерацию проверяется путей на половину таблицы
        this->MethodBase::iterationFinalization(bigGraph, smallGraph, isoMatr, isoP);
        return 0;
    }
    virtual void Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit)
    {
        this->MethodBase::Init(smallSize, bigSize, _goal, iterationCounter2, _iterationLimit);
        checkedP.clear();
        noMorePossibleCombinations = false;
    }
    GreedMethod() {}
private:
    std::vector<std::vector<int>> checkedP;
    bool noMorePossibleCombinations;
};

