#include <vector>
#pragma once
class MetaMethodBase
{
    public:
        //методы
        virtual void meta(std::vector<std::vector<int>>& tableBig, std::vector<std::vector<int>>& tableSmall, int _iterationLimit) = 0;

};

