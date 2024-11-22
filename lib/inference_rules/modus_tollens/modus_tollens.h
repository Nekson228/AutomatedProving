#ifndef PROOFSYSTEM_MODUS_TOLLENS_H
#define PROOFSYSTEM_MODUS_TOLLENS_H

#include <vector>
#include <memory>
#include <unordered_set>

#include "inference_rules/inference_rule/inference_rule.h"
#include "inference_rules/inference_conclusion/inference_conclusion.h"
#include "expressions/expression_cast/expression_cast.h"



class ModusTollens final : public InferenceRule {
    mutable std::unordered_set<std::pair<int, int>, pair_hash> usedPairs;

    [[nodiscard]] std::string getCodeName() const override {
        return "MT";
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

#endif //PROOFSYSTEM_MODUS_TOLLENS_H
