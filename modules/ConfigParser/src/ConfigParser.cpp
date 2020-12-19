#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <fstream>

#include "ConfigParser.hpp"
#include "VariablesMap.hpp"

ConfigParser::ConfigParser(const std::string& filename)
{
    variables = std::make_shared<VariablesMap>(); 
    std::ifstream fcin(filename.c_str());
    while (!fcin.eof())
    {
        std::string row;
        getline(fcin, row);
        rowParser(row);
    }
}

VariableInterface& ConfigParser::operator[](const std::string& name)
{
    auto& variables = *(this->variables);
    return variables[name];
}
const VariableInterface& ConfigParser::operator[](const std::string& name) const
{
    auto& variables = *(this->variables);
    return variables[name];
}
VariablesMapInterface& ConfigParser::holder()
{
    auto& variables = *(this->variables);
    return variables;
}

std::string::const_iterator ConfigParser::nameRead(std::string& oName, const std::string& row, char delimiter)
{
    auto it = row.cbegin();
    for (; it != row.cend(); ++it)
    {
        if (*it == delimiter)
            break;
        if (*it == '#')
        {
            return row.cend();
        }
        oName.push_back(*it);
    }
    return it;
}

void ConfigParser::valueRead(std::string& oValue, const std::string& row, std::string::const_iterator it)
{
    for (; it != row.cend(); ++it)
    {
        if (*it == '#')
            break;
        oValue.push_back(*it);
    }
}

void ConfigParser::equalParser(const std::string& row)
{
    auto& variables = *(this->variables);
    std::string name, value;
    valueRead(value, row, ++nameRead(name, row, '='));
    variables[name] = value;
}

void ConfigParser::plusParser(const std::string& row)
{
    auto& variables = *(this->variables);
    std::string name, value;
    valueRead(value, row, ++nameRead(name, row, '+'));
    variables[name] + value;
}

ConfigParser::TypeAction ConfigParser::getTypeAction(const std::string& row)
{
    for (auto el : row)
    {
        if (el == '=')
            return TypeAction::Equal;
        if (el == '+')
            return TypeAction::Plus;
        if (el == '#')
            return TypeAction::Comment;
    }
    return TypeAction::None;
}

void ConfigParser::rowParser(const std::string& row)
{
    auto action = getTypeAction(row);

    switch (action)
    {
        case TypeAction::Equal:
            return equalParser(row);
        case TypeAction::Plus:
            return plusParser(row);
        default:
            std::runtime_error("Action is undefined");
    }
}




