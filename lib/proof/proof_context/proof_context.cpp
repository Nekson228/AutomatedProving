#include "proof_context.h"

bool ProofContext::addConclusionIfNew(const std::shared_ptr<Expression> &conclusion) {
    if (const std::string repr = conclusion->toString(); visited.find(repr) == visited.end()) {
        known.push_back(conclusion);
        visited.insert(repr);
        updated = true;
        return true;
    }
    return false;
}

bool ProofContext::isTargetReached(const std::shared_ptr<Expression> &conclusion) const {
    return conclusion->equals(target);
}
