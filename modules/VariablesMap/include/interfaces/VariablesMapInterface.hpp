#pragma once
#include <string>
#include <unordered_map>

#include "interfaces/VariableInterface.hpp"

class VariablesMapInterface
{
public:
    virtual VariableInterface& operator[](const std::string& name) = 0;
    virtual const VariableInterface& operator[](const std::string& name) const = 0;
};