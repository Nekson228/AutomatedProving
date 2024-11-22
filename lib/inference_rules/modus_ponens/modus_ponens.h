#ifndef MODUS_PONENS_H
#define MODUS_PONENS_H

#include <vector>
#include <memory>
#include <unordered_set>

#include "inference_rules/inference_rule/inference_rule.h"
#include "inference_rules/inference_conclusion/inference_conclusion.h"
#include "expressions/expression_cast/expression_cast.h"

struct pair_hash {
    std::size_t operator()(const std::pair<int, int> &v) const {
        return v.first * 31 + v.second;
    }
};

class ModusPonens final : public InferenceRule {
    mutable std::unordered_set<std::pair<int, int>, pair_hash> usedPairs;

    [[nodiscard]] std::string getCodeName() const override {
        return "MP";
    }

    [[nodiscard]] static std::vector<EnumeratedImplication> findImplications(
        const std::vector<EnumeratedExpression> &statements
    );

    void addMatchingConclusions(
        const EnumeratedImplication &implication, const std::vector<EnumeratedExpression> &statements,
        std::vector<InferenceConclusion> &conclusions
    ) const;

public:
    [[nodiscard]] std::vector<InferenceConclusion> apply(
        const std::vector<EnumeratedExpression> &knownStatements
    ) const override;
};

#endif // MODUS_PONENS_H
