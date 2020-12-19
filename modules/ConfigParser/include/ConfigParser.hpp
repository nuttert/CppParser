#pragma once

#include <string>
#include <memory>

#include "interfaces/ConfigParserInterface.hpp"

class ConfigParser: public ConfigParserInterface
    {
        enum class TypeAction
        {
            None,
            Equal,
            Plus,
            Comment
        };
    public:
        ConfigParser(const std::string& filename);
        VariableInterface& operator[](const std::string& name) override;
        const VariableInterface& operator[](const std::string& name) const override;
        VariablesMapInterface& holder() override;
    private:
        std::string::const_iterator nameRead(std::string& oName, const std::string& row, char delimiter);
        void valueRead(std::string& oValue, const std::string& row, std::string::const_iterator it);

        void equalParser(const std::string& row);
        void plusParser(const std::string& row);
        void rowParser(const std::string& row);

        TypeAction getTypeAction(const std::string& row);
    private:
        std::shared_ptr<VariablesMapInterface> variables;
    };