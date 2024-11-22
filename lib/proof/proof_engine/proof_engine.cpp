#include "proof_engine.h"

ProofEngine::ProofEngine(const std::vector<std::shared_ptr<Expression> > &axioms,
                         const std::vector<std::shared_ptr<InferenceRule> > &rules): rules(rules), axioms(axioms) {
}

bool ProofEngine::prove(ProofContext &context) const {
    while (context.current_step < MAX_PROOF_STEPS) {
        context.markUpdated(false);

        applyInferenceRules(context);

        if (context.hasUpdates() && context.isTargetReached(context.known.back()))
            return true;
        if (not context.hasUpdates())
            return false;
    }
    return false;
}

void ProofEngine::applyInferenceRules(ProofContext &context) const {
    for (const auto &rule: rules) {
        applySingleInferenceRule(context, rule);
        if (context.hasUpdates() && context.isTargetReached(context.known.back()))
            return;
    }
}

void ProofEngine::applySingleInferenceRule(ProofContext &context, const std::shared_ptr<InferenceRule> &rule) {
    auto conclusions = rule->apply(context.known);
    for (const auto &conclusion: conclusions) {
        context.addConclusionIfNew(conclusion);
        if (context.isTargetReached(context.known.back()))
            return;
    }
}
