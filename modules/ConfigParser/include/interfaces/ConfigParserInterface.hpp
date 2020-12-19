#pragma once
#include <string>

#include "interfaces/VariableInterface.hpp"
#include "interfaces/VariablesMapInterface.hpp"

class ConfigParserInterface
{
public:
    virtual VariableInterface& operator[](const std::string& name) = 0;
    virtual const VariableInterface& operator[](const std::string& name) const = 0;
    virtual VariablesMapInterface& holder() = 0;
};