#include <vector>
#include "FullMethod.h"
#include "RandomMethod.h"
#include "GreedMethod.h"
#include "RWMethod.h"
#include "SAMethod.h"
#pragma once

class supervisor
{
public:
    int getIterationCounter(int pairNumber, int methodNumber);
    bool getFinishFlag(int methodNumber);
    std::vector<std::vector<int>> getIsomoph(int pairNumber, int methodNumber);
    std::vector<int> getIsomorphP(int pairNumber, int methodNumber);
    bool IterationAll(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph);
    std::vector<int> getEmptyVector(int size);
    std::vector<std::vector<int> > getEmptyGraph(int size);
    std::vector<std::vector<std::vector<int> >> getEmptyVectorGraphs(int graphSize, int vectorSize);
    void InitAll(int n, int n2, int _goal);
    void ClearingTotalAll();
    void FindLocalStatsAll();
    void FindGlobalStatsAll(int sizeOfSample);
    
    std::vector<double> Metaoptimization(int methodNumber, std::vector<std::vector<std::vector<int>> >& sampleGraphBigMeta,
        std::vector<std::vector<std::vector<int>> >& sampleGraphSmallMeta, double& param_val_init, double& param_val_step, int parameterToOptimize);
    void setParameterInMethod(int methodNumber, int parameter, double value);
    supervisor(std::vector<int> methodsEnableFlags, int _goal, int _iterationLimit);
    void fillSolutionsContainers(std::vector<std::vector<std::vector<int>> >& sampleGraphSmall);
    void getMethodStats(int methodNumber, double& averageQ, double& prob, double& dispers, double& sigma, double& dQ);
    int getMethodCount();
    std::string getMetaMethodName(int metaMethodNumber);
private:
    std::vector<MethodBase*> methodList;
    std::vector<MetaMethodBase*> metaMethodsList;
    std::vector<bool> methodsFinishFlags;
    std::vector<std::vector<int>> iterationCountersList;  //пара графов-метод-счётчик итераций
    std::vector<std::vector<std::vector<int>> > methodsIsomorphsP;
    std::vector<std::vector<std::vector<std::vector<int>> >> methodsIsomorphs;
    int goal;
    int pairNumber;
    int pairCount;
    int iterationLimit;
};

