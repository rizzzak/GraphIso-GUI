#pragma once
#include "MethodBase.h"
class RandomMethod :
    public MethodBase
{
    public:
        virtual int Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP);
        virtual void Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit);
        RandomMethod() {}
};

