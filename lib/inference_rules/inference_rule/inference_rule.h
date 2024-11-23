#ifndef INFERENCE_RULE_H
#define INFERENCE_RULE_H

#include <memory>
#include <vector>

#include "expressions/expression/expression.h"
#include "expressions/implication/implication.h"
#include "expressions/disjunction/disjunction.h"
#include "expressions/exclusive_or/exclusive_or.h"
#include "inference_rules/inference_conclusion/inference_conclusion.h"

using EnumeratedExpression = std::pair<int, std::shared_ptr<Expression> >;
using EnumeratedImplication = std::pair<int, std::shared_ptr<Implication> >;
using EnumeratedDisjunction = std::pair<int, std::shared_ptr<Disjunction> >;
using EnumeratedExclusiveOr = std::pair<int, std::shared_ptr<ExclusiveOr> >;



struct pair_hash {
    std::size_t operator()(const std::pair<int, int> &v) const {
        return v.first * 31 + v.second;
    }
};

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
