#include "VariablesMap.hpp"
#include "utils.hpp"
#include "config.hpp"
#include "Variable.hpp"

VariableInterface& VariablesMap::operator[](const std::string& name)
{
    std::string cName = name;
    deleteCharacters(cName, config::ExtraCharactersName);
    if (variables.find(cName) == variables.end())
        variables[cName] = std::make_shared<Variable>(cName);
    return *(variables[cName]);
}

const VariableInterface& VariablesMap::operator[](const std::string& name) const
{
    std::string cName = name;
    deleteCharacters(cName, config::ExtraCharactersName);
    auto it = variables.find(cName);
    
    if(it == variables.end()) std::runtime_error("Index out of range");
    return *(it->second);
}