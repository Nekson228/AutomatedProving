#include "proof_engine.h"

#include "expressions/expression_cast/expression_cast.h"

ProofEngine::ProofEngine(const std::vector<std::shared_ptr<Expression> > &axioms,
                         const std::vector<std::shared_ptr<InferenceRule> > &rules): rules(rules), axioms(axioms) {
    for (const auto &axiom: axioms) {
        this->axioms_schemes.push_back(std::make_shared<AxiomScheme>(axiom));
    }
}

bool ProofEngine::prove(const std::shared_ptr<Expression> &target) const {
    ProofContext context(axioms, target);
    while (true) {
        context.markUpdated(false);

        applyInferenceRules(context);

        if (context.hasUpdates() && context.isTargetReached(context.known.back()))
            return true;
        if (not context.hasUpdates())
            return false;
    }
}

void ProofEngine::applyInferenceRules(ProofContext &context) const {
    for (const auto &rule: rules) {
        applySingleRule(context, rule);
    }
}


void ProofEngine::applySingleRule(ProofContext &context, const std::shared_ptr<InferenceRule> &rule) {
    auto conclusions = rule->apply(context.known);
    for (const auto &conclusion: conclusions) {
        context.addConclusionIfNew(conclusion);
        if (context.isTargetReached(conclusion))
            return;
    }
}
