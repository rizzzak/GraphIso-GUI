#include <vector>
#include <string>
#pragma once
class MethodBase
{
    public:
        virtual int Iteration(std::vector<std::vector<int>>& tableBig, std::vector<std::vector<int>>& tableSmall, 
            std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP) = 0;
        virtual void Init(int smallSize, int bigSize, int _goal, int* iterationCounter2, int _iterationLimit);
        double getAverageQ();
        double getProbability();
        double getDispersion();
        double getSigma();
        double getDeltaQ();
        void FindLocalStats();
        void FindGlobalStats(int sizeOfSample);
        void ClearingTotal();
        int compareTables(std::vector<std::vector<int>> table, std::vector<std::vector<int>> table2, int n);
        std::vector<std::vector<int>> buildGraphFromP(std::vector<int> p, std::vector<std::vector<int>> source);
        std::vector<std::vector<int>> genGraphWithDensity(int n, double D);
        std::string getVectorInt(std::vector<int> vec, std::string name = "");
        void iterationFinalization(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP);
        void iterationFinalization(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, int& metaMinQ);
    protected:
        double averageQ;
        double probability;
        double dispersion;
        double sigma;
        double deltaQ;
        double localAverageQ;
        double localProbability;
        std::vector<double> vector_Q;
        std::vector<int> p;
        std::vector<std::vector<int>> pSolutions;
        int* iterationCounter;
        int localQ;
        int localMinQ;
        int iterationLimit;
        int solutionsCounter;
        int isomorphsFoundCounter;
        int isomorphsFoundGoal;
        bool iterationLimitExceed;
        bool solutionsFound;
    private:
        double epsilon = 0.0001;
        
};

