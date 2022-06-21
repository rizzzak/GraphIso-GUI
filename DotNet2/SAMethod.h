#pragma once
#include "MethodBase.h"
#include "MetaMethodBase.h"
class SAMethod :
    public MethodBase, public MetaMethodBase
{
    public:
        virtual int Iteration(std::vector<std::vector<int>>& graphBig, std::vector<std::vector<int>>& graphSmall, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP);
        virtual int Iteration(std::vector<std::vector<int>>& graphBig, std::vector<std::vector<int>>& graphSmall, int& metaMinQ);
        virtual void Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit);
        virtual std::vector<double> meta(std::vector<std::vector<std::vector<int>> >& sampleGraphBigMeta,
            std::vector<std::vector<std::vector<int>> >& sampleGraphSmallMeta,
            int _iterationLimit, double& param_val_init, double& param_val_step, std::vector<double>& out_prob, int parameterToOptimize = 0);
        SAMethod() 
        {
            T = 1000;
            Gamma = 0.1;
        }
        virtual void setParameter(int parameterNumber, double value);
        virtual double getParameter(int parameterNumber);
        
    private:
        double T, Gamma;
        std::vector<std::vector<int>> checkedP;
        bool isStucked;
};

