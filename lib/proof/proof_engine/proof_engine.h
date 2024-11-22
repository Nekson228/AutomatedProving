#ifndef PROOF_ENGINE_H
#define PROOF_ENGINE_H

#include <memory>
#include <vector>

#include "expressions/expression/expression.h"
#include "inference_rules/inference_rule/inference_rule.h"
#include "proof/proof_context/proof_context.h"

constexpr int MAX_PROOF_STEPS = 100000;

class ProofEngine {
    std::vector<std::shared_ptr<InferenceRule> > rules;
    std::vector<std::shared_ptr<Expression> > axioms;

    void applyInferenceRules(ProofContext &context) const;

    static void applySingleInferenceRule(ProofContext &context, const std::shared_ptr<InferenceRule> &rule);

public:
    explicit ProofEngine(const std::vector<std::shared_ptr<Expression> > &axioms,
                         const std::vector<std::shared_ptr<InferenceRule> > &rules);

    [[nodiscard]] bool prove(ProofContext &context) const;
};

#endif // PROOF_ENGINE_H
