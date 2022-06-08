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
    int getIterationCounter(int pairNumber, int methodNumber)
    {
        return iterationCountersList[pairNumber][methodNumber];
    }
    bool getFinishFlag(int methodNumber)
    {
        return methodsFinishFlags[methodNumber];
    }
    std::vector<std::vector<int>> getIsomoph(int pairNumber, int methodNumber)
    {
        return methodsIsomorphs[pairNumber][methodNumber];
    }
    std::vector<int> getIsomorphP(int pairNumber, int methodNumber)
    {
        std::vector<std::vector<int>> tempVec = methodsIsomorphsP[pairNumber];
        std::vector<int > tempVec2 = methodsIsomorphsP[pairNumber][methodNumber];
        return methodsIsomorphsP[pairNumber][methodNumber];
    }
    bool IterationAll(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph) {
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
    std::vector<int> getEmptyVector(int size)
    {
        std::vector<int> graphString;
        for (int j = 0; j < size; j++)
        {
            graphString.push_back(0);
        }
        return graphString;
    }
    std::vector<std::vector<int> > getEmptyGraph(int size)
    {
        std::vector<std::vector<int>> graph;
        
        for (int i = 0; i < size; i++)
        {
            graph.push_back(getEmptyVector(size));
        }
        return graph;
    }
    std::vector<std::vector<std::vector<int> >> getEmptyVectorGraphs(int graphSize, int vectorSize)
    {
        std::vector < std::vector<std::vector<int>>> vectorGraphs;

        for (int i = 0; i < vectorSize; i++)
        {
            vectorGraphs.push_back(getEmptyGraph(graphSize));
        }
        return vectorGraphs;
    }
    void InitAll(int n, int n2, int _goal) {
        pairNumber++;
        for (int i = 0; i < methodsFinishFlags.size(); i++)
        {
            methodsFinishFlags[i] = false;
            methodList[i]->Init(n, n2, goal, &iterationCountersList[pairNumber][i], iterationLimit);  
        }
    }
    void ClearingTotalAll() {
        for (std::vector<MethodBase*>::iterator a = methodList.begin(); a < methodList.end(); a++)
            (*a)->ClearingTotal();
    }
    void FindLocalStatsAll() {
        for (std::vector<MethodBase*>::iterator a = methodList.begin(); a < methodList.end(); a++)
            (*a)->FindLocalStats();
    }
    void FindGlobalStatsAll(int sizeOfSample) {
        for (std::vector<MethodBase*>::iterator a = methodList.begin(); a < methodList.end(); a++)
            (*a)->FindGlobalStats(sizeOfSample);
    }
    
    void MetaoptimizationAll(std::vector<std::vector<int>>& tableBig, std::vector<std::vector<int>>& tableSmall) {
        for (std::vector<MetaMethodBase*>::iterator a = metaMethodsList.begin(); a < metaMethodsList.end(); a++)
            (*a)->meta(tableBig, tableSmall, iterationLimit);
    }
    supervisor(double d, std::vector<int> methodsEnableFlags, int _goal, int _iterationLimit)
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
                RWMethod* rwm = new RWMethod(d);
                methodList.push_back(rwm);
                metaMethodsList.push_back(rwm);
            }
            else if (i == 4 && methodsEnableFlags[i] == 1)
            {
               // SAMethod* sam = new SAMethod();
                //methodList.push_back(sam);
               // metaMethodsList.push_back(sam);
            }
        }
    }
    void addPairs(std::vector<std::vector<std::vector<int>> >& sampleGraphSmall)
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
    void getMethodStats(int methodNumber, double& averageQ, double& prob, double& dispers, double& sigma, double& dQ)
    {
        averageQ = methodList[methodNumber]->getAverageQ();
        prob = methodList[methodNumber]->getProbability();
        dispers = methodList[methodNumber]->getDispersion();
        sigma = methodList[methodNumber]->getSigma();
        dQ = methodList[methodNumber]->getDeltaQ();
    }
    int getMethodCount() {
        return methodList.size();
    }
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

