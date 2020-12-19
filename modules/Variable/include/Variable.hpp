#pragma once
#include "interfaces/VariableInterface.hpp"


class Variable: public VariableInterface
{
public:
    Variable() = default;
    Variable(const std::string& name);
    Variable(const std::string& name, const std::string& value);

    Variable& operator=(const std::string& newValue) override;
    Variable& operator+(const std::string& end) override;

    const std::string& getName() const override;
    const std::string& getValue() const override;

private:
    std::string name;
    std::string value;
};