#include "utils.hpp"
#include <vector>
#include <algorithm>

std::optional<char> deleteCharacters(std::string& ioString, const std::vector<char>& needDelete)
{   
    std::optional<char> extra;

    auto checkNeedDelete = [&extra, needDelete](char sym)
    {
        auto iterator = std::find(needDelete.cbegin(), needDelete.cend(), sym);
        if(iterator == needDelete.end()) return false;
        extra = *iterator;
        return true;
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
    return extra;
}