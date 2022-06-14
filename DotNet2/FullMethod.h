#pragma once
#include "MethodBase.h"
#include <vector>
class FullMethod :
    public MethodBase
{
public:
    virtual int Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP);
    virtual void Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit);
    FullMethod() {}
    
private:
    // ���������� ��������� ����������, ��������� ������ a
    // smallSize - ����� ���������
    // k - ����������� ����������
    bool NextPermutation(std::vector<int>& a, int k, int smallSize);
    //������
    bool noMorePossibleCombinations;
};

