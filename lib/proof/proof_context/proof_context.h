#ifndef PROOF_CONTEXT_H
#define PROOF_CONTEXT_H

#include "expressions/expression/expression.h"
#include "axiom/axiom_scheme/axiom_scheme.h"

#include <unordered_set>
#include <vector>
#include <memory>
#include <string>

class ProofContext {
public:
    std::vector<std::shared_ptr<Expression> > known;
    std::unordered_set<std::string> visited;
    std::shared_ptr<Expression> target;
    bool updated = false;

    explicit ProofContext(const std::vector<std::shared_ptr<Expression> > &axioms,
                          const std::shared_ptr<Expression> &target)
        : known(axioms), target(target) {
    }

    bool addConclusionIfNew(const std::shared_ptr<Expression> &conclusion);

    bool isTargetReached(const std::shared_ptr<Expression> &conclusion) const;

    void markUpdated(const bool state) { updated = state; }

    bool hasUpdates() const { return updated; }
};

#endif // PROOF_CONTEXT_H
