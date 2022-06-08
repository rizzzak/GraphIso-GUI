#pragma once
#include "MethodBase.h"
#include "MetaMethodBase.h"
class RWMethod :
    public MethodBase, public MetaMethodBase
{
public:
    virtual int Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP)
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
        this->MethodBase::iterationFinalization(bigGraph, smallGraph, isoMatr, isoP);
        return 0;
    }
    virtual void Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit)
    {
        this->MethodBase::Init(smallSize, bigSize, _goal, iterationCounter2, _iterationLimit);
        isNoMorePossibleCombinations = false;
        checkedP.clear();
    }
    virtual void meta(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, int _iterationLimit)
    {
        std::vector<int> iterationsToGetSolution;
        int smallSize = smallGraph.size();
        int bigSize = bigGraph.size();
        for (d = 0; d < 1.01; d += 0.05)
        {
            Init(smallSize, bigSize, 1, new int(0), _iterationLimit);
            //while (!Iteration(bigGraph, smallGraph)) {}
            iterationsToGetSolution.push_back((*iterationCounter) * bigGraph.size() * (bigGraph.size() - 1) / 2);
        }
        int minElementIndex = 0;
        int metaMinIterations = 1000000;
        for (int i = 0; i < iterationsToGetSolution.size(); i++)
        {
            if (metaMinIterations > iterationsToGetSolution[i])
            {
                metaMinIterations = iterationsToGetSolution[i];
                minElementIndex = i;
            }
        }
        d = minElementIndex * 0.05;
        //cout << "\smallSizeМетаоптимизация проведена, оптимальное значение d = " << to_string(d);
    }
    RWMethod(double D) { d = D; }

private:
    std::vector<std::vector<int>> checkedP;
    bool isNoMorePossibleCombinations;
    double d;
};

