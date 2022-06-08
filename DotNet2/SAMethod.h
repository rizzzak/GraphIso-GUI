#pragma once
#include "MethodBase.h"
#include "MetaMethodBase.h"
class SAMethod :
    public MethodBase, public MetaMethodBase
{
    public:
        //методы
        virtual void Close()
        {
            //outSA.close();
            //outSAMeta.close();
        }
        virtual void Open()
        {
            //outSA.open("SA.csv");
            //outSAMeta.open("SA Meta.csv");
        }
        virtual void DocHeader(int Delta, double D) { 
            //outSA << "Delta = " << Delta << ", Density = " << D << "\smallSize"; 
        }
        virtual int Iteration(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph, std::vector<std::vector<int>>& isoMatr, std::vector<int>& isoP) {
            if (solutionsFound)
                return 1;
            
            int bigSize = bigGraph.size();
            int smallSize = smallGraph.size();
            std::vector<int> shortPerestanovka;
            int localQOld = localQ;
            std::vector<int> pOld = p;
            int i = 1, j = 1;
            while (i == j)
            {
                i = rand() % bigSize;
                j = rand() % bigSize;
            }
            std::swap(p[i], p[j]);
            for (int k = 0; k < smallSize; k++)
                shortPerestanovka.push_back(p[k]);
            std::vector<std::vector<int>> newGraph = buildGraphFromP(shortPerestanovka, bigGraph);
            localQ = compareTables(newGraph, smallGraph, smallSize);
            (*iterationCounter)++;

            //мутация - случайный свап? вброс вершины вне мелкого графа в него на место случайной вершины?

            if (localQ >= localQOld)
            {
                if (localQ > 0)
                {
                    double f = exp(localQ / T);
                    double rk = rand() / (double)RAND_MAX;
                    if (rk > f)
                        p = pOld;
                }

            }
            if (localMinQ > localQ)
                localMinQ = localQ;
            localAverageQ += localQ;
            if (localQ == 0)
                localProbability += 1.0;
            
            // охлаждение()
            T *= Gamma;

            if (localQ == 0)
            {
                //протоколирование перестановок-изоморфов
                //cout << "\t\t\t\tМетод имитации отжига нашел ответ за " << iterationCounter << " итераций!\smallSize";
                std::vector<int> shortPerestanovka;
                for (int i = 0; i < smallGraph.size(); i++)
                {
                    shortPerestanovka.push_back(p[i]);
                }
                if (find(pSolutions.begin(), pSolutions.end(), shortPerestanovka) == pSolutions.end())
                {
                    /*cout << "\t\t\t\tИзоморфная перестановка:";
                    for (int i = 0; i < smallGraph.size(); i++)
                    {
                        cout << " " << p[i];
                    }
                    cout << "\smallSize";*/
                    isomorphsFoundCounter++;
                    pSolutions.push_back(shortPerestanovka);
                    isoMatr = buildGraphFromP(shortPerestanovka, bigGraph);
                    isoP = shortPerestanovka;
                }

                //проверка условия окончания работы метода
                if (isomorphsFoundCounter == isomorphsFoundGoal)
                    solutionsFound = true;
            }
            return 0;
        }
        virtual void Init(int smallSize, int bigSize, int _goal, int* iterationCounter2)
        {
            std::vector<int> perestanovka;
            localQ = smallSize * smallSize;
            localMinQ = smallSize * smallSize;
            for (int i = 0; i < bigSize; i++)
            {
                perestanovka.push_back(i);
            }
            p = perestanovka;
            T = TStart;
            localAverageQ = 0.;
            localProbability = 0.;
            iterationCounter = iterationCounter2;
            solutionsCounter = 0;
            solutionsFound = false;
            pSolutions.clear();
            isomorphsFoundCounter = 0;
            isomorphsFoundGoal = _goal;

            averageQ = 0.;
            totalProbability = 0.;
            dispersion = 0.;
            sigma = 0.;
            deltaQ = 0.;
            localAverageQ = 0.;
            localQ = 0.;
            localProbability = 0.;
            localMinQ = 0.;
        }
        virtual void FindLocalStats()
        {
            localAverageQ /= (*iterationCounter);
            localProbability /= (*iterationCounter);
            if (localProbability > 0.)
            {
                totalProbability += 1.0;
                vector_Q.push_back(0);
            }
            else
            {
                vector_Q.push_back(localMinQ);
            }
        }
        virtual void FindGlobalStats(int sizeOfSample)
        {
            totalProbability /= sizeOfSample;
            for (int i = 0; i < vector_Q.size(); i++)
            {
                averageQ += vector_Q[i];
            }
            averageQ /= sizeOfSample;
            for (int i = 0; i < vector_Q.size(); i++)
            {
                dispersion += pow((vector_Q[i] - averageQ), 2);
            }
            dispersion /= sizeOfSample;
            sigma = sqrt(dispersion);
            deltaQ = 1.96 * sigma / sqrt(sizeOfSample);
            Doc();
        }
        virtual void ClearingTotal()
        {
            vector_Q.clear();
            totalProbability = 0;
            averageQ = 0;
            dispersion = 0;
        }
        
        virtual void meta(std::vector<std::vector<int>>& bigGraph, std::vector<std::vector<int>>& smallGraph)
        {
            std::vector<double> totalMinQSAMO;
            int smallSize = smallGraph.size();
            int bigSize = bigGraph.size();
            DocHeaderMeta();
            //cout << "\smallSize SA Meta: ";
            for (TStart = 1; TStart < 1024; TStart *= 2)
            {

                for (Gamma = 0.1; Gamma < 1.1; Gamma += 0.1)
                {
                    //cout << "\smallSizeТемпература=" << TStart << ", гамма=" << Gamma << ": ";
                    Init(smallSize, bigSize, 1, int(0));
                    //while (!Iteration(bigGraph, smallGraph)) {}
                    FindLocalStats();
                    DocMeta(TStart, Gamma, (*iterationCounter));
                    metaIterationCount.push_back(*iterationCounter);
                    //cout << "x";
                }
                //cout << "\smallSize";
            }
            int minElementIndex = 0;
            int tempMinIterationCount = 9999;
            for (int i = 0; i < metaIterationCount.size(); i++)
            {
                if (tempMinIterationCount > metaIterationCount[i])
                {
                    tempMinIterationCount = metaIterationCount[i];
                    minElementIndex = i;
                }
            }
            metaIterationCount.clear();

            //TODO НЕВЕРНО = 6 получилось
            TStart = pow(2, ((minElementIndex - minElementIndex % 10) / 10));
            Gamma = 0.1 + 0.1 * (minElementIndex % 10);

            //cout << "\smallSize\smallSizeМетаоптимизация проведена, оптимальные значения настроечных параметров:";
            //cout << "\smallSize\tНачальная температура = " << to_string(TStart);
            //cout << "\smallSize\tКоэффициент остывания металла = " << to_string(Gamma) << "\smallSize";
        }
        SAMethod() 
        {
        }
        SAMethod(double tStart, double gamma) 
        {
            TStart = tStart; Gamma = gamma;
        }
        
    private:
        virtual void Doc()
        {
            /*outSA << to_string(totalProbability) << ";";
            outSA << to_string(averageQ) << ";";
            outSA << to_string(dispersion) << ";";
            outSA << to_string(sigma) << ";";
            outSA << to_string(deltaQ) << ";";
            outSA << "[" << to_string(averageQ - deltaQ) << "; " << to_string(averageQ + deltaQ) << "]\smallSize";*/
        }
        void DocHeaderMeta() {
            //outSAMeta << "; ; итераций для получения изоморфа \smallSize";
        }
        void DocMeta(double tStart, double gamma, int iterationsCount) {
            //outSAMeta << "T(start) = " << tStart << "; gamma = " << gamma << ";" << to_string(iterationsCount) << "\smallSize";
        }
        //данные
        double averageQ;
        std::vector<double> vector_Q;
        double totalProbability;
        double dispersion;
        double sigma;
        double deltaQ;
        //local stats
        double localAverageQ;
        int localQ;
        double localProbability;
        int localMinQ;
        std::vector<int> p;
        int* iterationCounter;
        int solutionsCounter;
        bool solutionsFound;
        int isomorphsFoundCounter;
        int isomorphsFoundGoal;
        std::vector<std::vector<int>> pSolutions;
        std::vector<int> metaIterationCount;
        double T;
        double TStart = 1000, Gamma = 0.1;
};

