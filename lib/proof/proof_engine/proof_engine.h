#ifndef PROOF_ENGINE_H
#define PROOF_ENGINE_H

#include "expressions/expression/expression.h"
#include "inference_rules/inference_rule/inference_rule.h"
#include "proof/proof_context/proof_context.h"
#include "axiom/axiom_scheme/axiom_scheme.h"

#include <memory>
#include <vector>


class ProofEngine {
    std::vector<std::shared_ptr<InferenceRule> > rules;
    std::vector<std::shared_ptr<Expression> > axioms;
    std::vector<std::shared_ptr<AxiomScheme> > axioms_schemes;

    void applyInferenceRules(ProofContext &context) const;

    static void applySingleRule(ProofContext &context, const std::shared_ptr<InferenceRule> &rule);

    bool unify(const std::shared_ptr<Expression> &expr1, const std::shared_ptr<Expression> &expr2,
               std::unordered_map<std::string, std::shared_ptr<Expression> > &mapping) const;

public:
    explicit ProofEngine(const std::vector<std::shared_ptr<Expression> > &axioms,
                         const std::vector<std::shared_ptr<InferenceRule> > &rules);

    [[nodiscard]] bool prove(const std::shared_ptr<Expression> &target) const;
};

#endif // PROOF_ENGINE_H
