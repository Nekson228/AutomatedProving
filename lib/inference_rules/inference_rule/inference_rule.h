#ifndef INFERENCE_RULE_H
#define INFERENCE_RULE_H

#include <memory>
#include <vector>

#include "expressions/expression/expression.h"
#include "expressions/implication/implication.h"
#include "inference_rules/inference_conclusion/inference_conclusion.h"

using EnumeratedExpression = std::pair<int, std::shared_ptr<Expression> >;
using EnumeratedImplication = std::pair<int, std::shared_ptr<Implication> >;

class InferenceRule {
    [[nodiscard]] virtual std::string getCodeName() const = 0;

protected:
    [[nodiscard]] InferenceConclusion createConclusion(const std::shared_ptr<Expression> &statement,
                                                       const std::vector<int> &arguments,
                                                       const std::string &unification
    ) const;

public:
    virtual ~InferenceRule() = default;

    [[nodiscard]] virtual std::vector<InferenceConclusion> apply(const std::vector<EnumeratedExpression> &statements
    ) const = 0;
};

#endif // INFERENCE_RULE_H
