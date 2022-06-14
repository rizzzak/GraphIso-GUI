#include "supervisor.h"
int supervisor::getIterationCounter(int pairNumber, int methodNumber)
{
    return iterationCountersList[pairNumber][methodNumber];
}
bool supervisor::getFinishFlag(int methodNumber)
{
    return methodsFinishFlags[methodNumber];
}
std::vector<std::vector<int>> supervisor::getIsomoph(int pairNumber, int methodNumber)
{
    return methodsIsomorphs[pairNumber][methodNumber];
}
std::vector<int> supervisor::getIsomorphP(int pairNumber, int methodNumber)
{
    std::vector<std::vector<int>> tempVec = methodsIsomorphsP[pairNumber];
    std::vector<int > tempVec2 = methodsIsomorphsP[pairNumber][methodNumber];
    return methodsIsomorphsP[pairNumber][methodNumber];
}
bool supervisor::IterationAll(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph) {
    int methodNumber = 0;
    for (std::vector<MethodBase*>::iterator a = methodList.begin(); a < methodList.end(); a++)
    {
        if ((*a)->Iteration(bigGraph, smallGraph, methodsIsomorphs[pairNumber][methodNumber], methodsIsomorphsP[pairNumber][methodNumber]))
            methodsFinishFlags[methodNumber] = true;
        methodNumber++;
    }
    bool isAllFinished = true;
    for (int i = 0; i < methodsFinishFlags.size(); i++)
    {
        if (!methodsFinishFlags[i])
            isAllFinished = false;
    }
    if (isAllFinished)
        return true;
    return false;
}
std::vector<int> supervisor::getEmptyVector(int size)
{
    std::vector<int> graphString;
    for (int j = 0; j < size; j++)
    {
        graphString.push_back(0);
    }
    return graphString;
}
std::vector<std::vector<int> > supervisor::getEmptyGraph(int size)
{
    std::vector<std::vector<int>> graph;

    for (int i = 0; i < size; i++)
    {
        graph.push_back(getEmptyVector(size));
    }
    return graph;
}
std::vector<std::vector<std::vector<int> >> supervisor::getEmptyVectorGraphs(int graphSize, int vectorSize)
{
    std::vector < std::vector<std::vector<int>>> vectorGraphs;

    for (int i = 0; i < vectorSize; i++)
    {
        vectorGraphs.push_back(getEmptyGraph(graphSize));
    }
    return vectorGraphs;
}
void supervisor::InitAll(int n, int n2, int _goal) {
    pairNumber++;
    for (int i = 0; i < methodsFinishFlags.size(); i++)
    {
        methodsFinishFlags[i] = false;
        methodList[i]->Init(n, n2, goal, &iterationCountersList[pairNumber][i], iterationLimit);
    }
}
void supervisor::ClearingTotalAll() {
    for (std::vector<MethodBase*>::iterator a = methodList.begin(); a < methodList.end(); a++)
        (*a)->ClearingTotal();
}
void supervisor::FindLocalStatsAll() {
    for (std::vector<MethodBase*>::iterator a = methodList.begin(); a < methodList.end(); a++)
        (*a)->FindLocalStats();
}
void supervisor::FindGlobalStatsAll(int sizeOfSample) {
    for (std::vector<MethodBase*>::iterator a = methodList.begin(); a < methodList.end(); a++)
        (*a)->FindGlobalStats(sizeOfSample);
}

std::vector<double> supervisor::Metaoptimization(int methodNumber, std::vector<std::vector<std::vector<int>> >& sampleGraphBigMeta,
    std::vector<std::vector<std::vector<int>> >& sampleGraphSmallMeta, double& param_val_init, double& param_val_step, int parameterToOptimize) {
    //метод возвращает вектор сигнатур оптимизируемого метода для построения графиков
    std::vector<double> sigs;
    sigs = metaMethodsList[methodNumber]->meta(sampleGraphBigMeta, sampleGraphSmallMeta,
        iterationLimit, param_val_init, param_val_step, parameterToOptimize);
    return sigs;
}
void supervisor::setParameterInMethod(int methodNumber, int parameter, double value)
{
    metaMethodsList[methodNumber]->setParameter(parameter, value);
}
supervisor::supervisor(std::vector<int> methodsEnableFlags, int _goal, int _iterationLimit)
{
    goal = _goal;
    pairNumber = -1;
    iterationLimit = _iterationLimit;
    //ассоциации с методами
    //  1. ПП
    //  2. СП
    //  3. ЖА
    //  4. СВП
    //  5. ИмОтж
    for (int i = 0; i < methodsEnableFlags.size(); i++)
    {
        if (methodsEnableFlags[i] == 1)
        {
            methodsFinishFlags.push_back(false);
        }
        if (i == 0 && methodsEnableFlags[i] == 1)
        {
            FullMethod* fm = new FullMethod();
            methodList.push_back(fm);
        }
        else if (i == 1 && methodsEnableFlags[i] == 1)
        {
            RandomMethod* rm = new RandomMethod();
            methodList.push_back(rm);
        }
        else if (i == 2 && methodsEnableFlags[i] == 1)
        {
            GreedMethod* gm = new GreedMethod();
            methodList.push_back(gm);
        }
        else if (i == 3 && methodsEnableFlags[i] == 1)
        {
            RWMethod* rwm = new RWMethod();
            methodList.push_back(rwm);
            metaMethodsList.push_back(rwm);
            rwm->setMethodName("Случайный взвешенный перебор");
        }
        else if (i == 4 && methodsEnableFlags[i] == 1)
        {
            SAMethod* sam = new SAMethod();
            methodList.push_back(sam);
            metaMethodsList.push_back(sam);
            sam->setMethodName("Метод имитации отжига");
        }
    }
}
void supervisor::fillSolutionsContainers(std::vector<std::vector<std::vector<int>> >& sampleGraphSmall)
{
    for (int i = 0; i < sampleGraphSmall.size(); i++)
    {
        std::vector<int> _vecIter;
        std::vector<std::vector<int>> _vecP;
        std::vector<std::vector<std::vector<int>> > _vecGraph;
        for (int j = 0; j < methodsFinishFlags.size(); j++)
        {
            _vecIter.push_back(0);
            _vecGraph.push_back(getEmptyGraph(sampleGraphSmall[i].size()));
            _vecP.push_back(getEmptyVector(sampleGraphSmall[i].size()));
        }
        iterationCountersList.push_back(_vecIter);
        methodsIsomorphsP.push_back(_vecP);
        methodsIsomorphs.push_back(_vecGraph);
    }
}
void supervisor::getMethodStats(int methodNumber, double& averageQ, double& prob, double& dispers, double& sigma, double& dQ)
{
    averageQ = methodList[methodNumber]->getAverageQ();
    prob = methodList[methodNumber]->getProbability();
    dispers = methodList[methodNumber]->getDispersion();
    sigma = methodList[methodNumber]->getSigma();
    dQ = methodList[methodNumber]->getDeltaQ();
}
int supervisor::getMethodCount() {
    return methodList.size();
}
std::string supervisor::getMetaMethodName(int metaMethodNumber)
{
    return metaMethodsList[metaMethodNumber]->getMethodName();
}