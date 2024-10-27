#ifndef PROOF_ENGINE_H
#define PROOF_ENGINE_H

#include "expression/expression.h"
#include <vector>
#include <memory>

class ProofEngine {
public:
    bool prove(const std::vector<std::shared_ptr<Expression>>& axioms, const std::shared_ptr<Expression>& target);
private:
    std::shared_ptr<Expression> applyModusPonens(const std::vector<std::shared_ptr<Expression>>& expressions);
};

#endif // PROOF_ENGINE_H
