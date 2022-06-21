#pragma once
#include "MethodBase.h"
#include "MetaMethodBase.h"
class RWMethod :
    public MethodBase, public MetaMethodBase
{
public:
    virtual int Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP);
    virtual int Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, int& metaMinQ);
    virtual void Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit);
    virtual std::vector<double> meta(std::vector<std::vector<std::vector<int>> >& sampleGraphBigMeta,
        std::vector<std::vector<std::vector<int>> >& sampleGraphSmallMeta, int _iterationLimit, double& param_val_init, double& param_val_step, std::vector<double>& out_prob, int parameterToOptimize = 0);
    virtual void setParameter(int parameterNumber, double value);
    virtual double getParameter(int parameterNumber);
    RWMethod() { d = 0.3; }

private:
    std::vector<std::vector<int>> checkedP;
    bool isNoMorePossibleCombinations;
    double d;

};

