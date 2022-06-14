#pragma once
#include "MethodBase.h"
#include <vector>
class FullMethod :
    public MethodBase
{
public:
    virtual int Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP)
    {
        if (solutionsFound || noMorePossibleCombinations || iterationLimitExceed)
            return 1;
        
        int q, smallSize = smallGraph.size(), bigSize = bigGraph.size();
        std::vector<int> shortPerestanovka;
        if (NextPermutation(p, smallSize, bigSize))
        {
            for (int i = 0; i < smallSize; i++)
                shortPerestanovka.push_back(p[i]);
            std::vector<std::vector<int>> newGraph = buildGraphFromP(shortPerestanovka, bigGraph);
            q = compareTables(newGraph, smallGraph, smallSize);
            localQ = q;
        }
        else
        {
            localQ = (smallSize * smallSize);
        }
        

        if (localQ == smallGraph.size() * smallGraph.size())
            noMorePossibleCombinations = true; //последн€€ итераци€ ѕѕ
        else
        {
            this->MethodBase::iterationFinalization(bigGraph, smallGraph, isoMatr, isoP);
        }
        
        return 0;
    }
    virtual void Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit)
    {
        this->MethodBase::Init(smallSize, bigSize, _goal, iterationCounter2, _iterationLimit);
        noMorePossibleCombinations = false;
    }
    FullMethod() {}
    
private:
    // генерирует следующее размещение, использу€ массив a
    // smallSize - всего элементов
    // k - вместимость размещени€
    bool NextPermutation(std::vector<int>& a, int k, int smallSize)
    {
        int edge, j, i, tmp;
        edge = k - 1;

        // find j in (kЕsmallSize-1) where a[j] > a[edge]
        j = k;
        while ((j < smallSize) && (a[edge] >= a[j])) ++j;

        if (j < smallSize)
        {
            // swap a[egde], a[j]
            tmp = a[edge], a[edge] = a[j], a[j] = tmp;
        }
        else
        {
            // reverse a[k] to a[smallSize-1]
            for (i = k, j = smallSize - 1; i < j; i++, j--)
            {
                tmp = a[i], a[i] = a[j], a[j] = tmp;
            }

            // find rightmost ascent to left of edge
            i = edge - 1;
            while (i >= 0 && a[i] >= a[i + 1]) --i;

            if (i < 0) return false;           // no more permutations

            // find j in (smallSize-1Еi+1) where aj > ai
            j = smallSize - 1;
            while (j > i && a[i] >= a[j]) --j;

            // swap a[i], a[j]
            tmp = a[i], a[i] = a[j], a[j] = tmp;

            // reverse a[i+1] to an-1
            for (i = i + 1, j = smallSize - 1; i < j; i++, j--)
            {
                tmp = a[i], a[i] = a[j], a[j] = tmp;
            }
        }
        return true;
    }
    //данные
    bool noMorePossibleCombinations;
};

