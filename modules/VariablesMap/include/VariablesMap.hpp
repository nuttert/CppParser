#pragma once
#include <memory>

#include "interfaces/VariablesMapInterface.hpp"
#include "interfaces/VariableInterface.hpp"


class VariablesMap: public VariablesMapInterface
{
    using VariablePtr = std::shared_ptr<VariableInterface>;
public:
    VariablesMap() = default;
    ~VariablesMap() = default;
    VariableInterface& operator[](const std::string& name) override;
    const VariableInterface& operator[](const std::string& name) const override;
private:
    std::unordered_map<std::string, VariablePtr> variables;
};