#ifndef PROOF_CONTEXT_H
#define PROOF_CONTEXT_H

#include <unordered_set>
#include <vector>
#include <memory>
#include <string>

#include "expressions/expression/expression.h"
#include "proof/proof_logger/proof_logger.h"

#include "inference_rules/inference_conclusion/inference_conclusion.h"

using EnumeratedExpression = std::pair<int, std::shared_ptr<Expression> >;

class ProofContext {
    bool updated = false;
    bool is_target_reached = false;

public:
    std::vector<EnumeratedExpression> known;
    std::unordered_set<std::string> visited;
    std::shared_ptr<Expression> target;

    ProofLogger logger;

    int current_step = 0;

    explicit ProofContext(const std::vector<std::shared_ptr<Expression> > &axioms,
                          const std::shared_ptr<Expression> &target);

    bool addConclusionIfNew(const InferenceConclusion &conclusion);

    bool isTargetReached(const EnumeratedExpression &conclusion);

    void markUpdated(const bool state) { updated = state; }

    bool hasUpdates() const { return updated; }

    const ProofLogger &getLogger() const { return logger; }
};

#endif // PROOF_CONTEXT_H
