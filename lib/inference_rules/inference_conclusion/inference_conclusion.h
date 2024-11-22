#ifndef INFERENCE_CONCLUSION_H
#define INFERENCE_CONCLUSION_H

#include <utility>
#include <vector>

#include "expressions/expression/expression.h"


struct InferenceConclusion {
    std::shared_ptr<Expression> expression;
    std::string inference_rule_name;
    std::vector<int> inference_rule_arguments;
    std::string substitution;

    InferenceConclusion(const std::shared_ptr<Expression> &expression,
                        std::string rule_name,
                        const std::vector<int> &rule_arguments,
                        std::string substitution): expression(expression),
                                                   inference_rule_name(std::move(rule_name)),
                                                   inference_rule_arguments(rule_arguments),
                                                   substitution(std::move(substitution)) {
    }
};


#endif //INFERENCE_CONCLUSION_H
