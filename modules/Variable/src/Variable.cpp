#include "Variable.hpp"
#include "utils.hpp"
#include "config.hpp"

Variable::Variable(const std::string& name):
   Variable(name, {})
{
    deleteCharacters(this->name, config::ExtraCharactersName);
}

Variable::Variable(const std::string& name, const std::string& value)
    : name(name), value(value)
{
    deleteCharacters(this->name, config::ExtraCharactersName);
    deleteCharacters(this->value, config::ExtraCharactersValue);
}

Variable& Variable::operator=(const std::string& newValue)
{
    value = newValue;
    deleteCharacters(value, config::ExtraCharactersValue);
    return *this;
}

Variable& Variable::operator+(const std::string& end)
{
    auto cEnd = end;
    deleteCharacters(cEnd, config::ExtraCharactersValue);
    value += cEnd;
    return *this;
}

const std::string& Variable::getName() const { return name; }
const std::string& Variable::getValue() const { return value; }