#include <vector>
#include <string>
#pragma once
class MetaMethodBase
{
    public:
        //методы
        virtual std::vector<double> meta(std::vector<std::vector<std::vector<int>> >& sampleGraphBigMeta,
            std::vector<std::vector<std::vector<int>> >& sampleGraphSmallMeta, int _iterationLimit, double& param_val_init, double& param_val_step, int parameterToOptimize) = 0;
        virtual void setParameter(int parameterNumber, double value) = 0;
        std::string getMethodName() { return methodName; }
        void setMethodName(std::string _name) { methodName = _name; }

    private:
        std::string methodName;
};

