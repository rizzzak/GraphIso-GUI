#pragma once
#include "MethodBase.h"
class RandomMethod :
    public MethodBase
{
    public:
        virtual int Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP)
        {
            if (solutionsFound || iterationLimitExceed)
                return 1; // 1 - признак окончания работы алгоритма - найдено заданное число изоморфов
            int q, randV, randV2, smallSize = smallGraph.size(), bigSize = bigGraph.size();
            std::vector<int> shortPerestanovka;
            while (true)
            {
                randV = rand() % bigSize;
                randV2 = rand() % bigSize;
                if (randV != randV2)
                    break;
            }
            std::swap(p[randV], p[randV2]);
            for (int i = 0; i < smallSize; i++)
            {
                shortPerestanovka.push_back(p[i]);
            }
            std::vector<std::vector<int>> newGraph = buildGraphFromP(shortPerestanovka, bigGraph); //большой граф заменяется подграфом с перенумерованными вершинами
            q = compareTables(smallGraph, newGraph, smallSize);
            localQ = q;
            this->MethodBase::iterationFinalization(bigGraph, smallGraph, isoMatr, isoP);
            return 0;
        }
        virtual void Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit)
        {
            this->MethodBase::Init(smallSize, bigSize, _goal, iterationCounter2, _iterationLimit);
        }
        RandomMethod() {}
};

