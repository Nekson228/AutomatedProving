#ifndef LOGENTITY_H
#define LOGENTITY_H

#include <optional>
#include <string>
#include <vector>

struct LogEntity {
    std::string statement;

    std::optional<std::string> inference_rule;
    std::optional<std::vector<int> > inference_rule_arguments;

    std::optional<std::string> substitution;
    std::optional<int> substitution_initial_expression;

    [[nodiscard]] std::string toString() const {
        std::string result;
        if (inference_rule.has_value()) {
            result += "[" + *inference_rule;
            for (const auto &argument: *inference_rule_arguments) {
                result += " " + std::to_string(argument);
            }
            result += "] ";
        }
        if (substitution_initial_expression.has_value())
            result += "[" + std::to_string(*substitution_initial_expression) + "] ";
        if (substitution.has_value())
            result += *substitution + " ";
        return result + statement;
    }
};

#endif //LOGENTITY_H
