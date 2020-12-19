#pragma once
#include <string>

class VariableInterface
{
public:
    virtual ~VariableInterface(){};
    virtual VariableInterface& operator=(const std::string& newValue) = 0;
    virtual VariableInterface& operator+(const std::string& end) = 0;

    virtual const std::string& getName() const = 0;
    virtual const std::string& getValue() const = 0;
};