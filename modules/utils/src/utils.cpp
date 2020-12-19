#include "utils.hpp"
#include <vector>
#include <algorithm>

void deleteCharacters(std::string& ioString, const std::vector<char>& needDelete)
{
    auto checkNeedDelete = [needDelete](char sym)
    {
        return std::find(needDelete.cbegin(), needDelete.cend(), sym) != needDelete.end();
    };
    auto runIter = ioString.begin();
    auto eraseIter = ioString.begin();
    while (runIter != ioString.end())
    {
        if (checkNeedDelete(*runIter))
        {
            ++runIter;
        } else
        {
            *eraseIter = *runIter;
            ++eraseIter;
            ++runIter;
        }
    }
    size_t newSize = eraseIter - ioString.begin();
    ioString.resize(newSize);
}