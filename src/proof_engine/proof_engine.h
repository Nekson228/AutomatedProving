#ifndef PROOF_ENGINE_H
#define PROOF_ENGINE_H

#include "expression/expression.h"

#include <vector>
#include <memory>

class ProofEngine {
    std::vector<std::shared_ptr<Expression> > axioms;

public:
    explicit ProofEngine(const std::vector<std::shared_ptr<Expression> > &axioms)
        : axioms(axioms) {
    }

    bool prove(const std::shared_ptr<Expression> &target);

private:
    static std::shared_ptr<Expression> prepareExpression(const std::shared_ptr<Expression> &expression);

    std::shared_ptr<Expression> applyModusPonens(const std::vector<std::shared_ptr<Expression> > &expressions);
};

#endif // PROOF_ENGINE_H
