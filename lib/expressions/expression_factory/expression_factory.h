#ifndef EXPRESSION_FACTORY_H
#define EXPRESSION_FACTORY_H

#include "expressions/implication/implication.h"
#include "expressions/negation/negation.h"
#include "expressions/variable/variable.h"
#include "expressions/conjunction/conjunction.h"
#include "expressions/disjunction/disjunction.h"
#include "expressions/exclusive_or/exclusive_or.h"
#include "expressions/equivalence/equivalence.h"

#include <memory>
#include <string>

namespace ExpressionFactory {
    inline std::shared_ptr<Expression> variable(const std::string &name) {
        return std::make_shared<Variable>(name);
    }

    inline std::shared_ptr<Expression> implication(const std::shared_ptr<Expression> &left,
                                                   const std::shared_ptr<Expression> &right) {
        return std::make_shared<Implication>(left, right);
    }

    inline std::shared_ptr<Expression> negation(const std::shared_ptr<Expression> &expr) {
        return std::make_shared<Negation>(expr);
    }

    inline std::shared_ptr<Expression> conjunction(const std::shared_ptr<Expression> &left,
                                                   const std::shared_ptr<Expression> &right) {
        return std::make_shared<Conjunction>(left, right);
    }

    inline std::shared_ptr<Expression> disjunction(const std::shared_ptr<Expression> &left,
                                                   const std::shared_ptr<Expression> &right) {
        return std::make_shared<Disjunction>(left, right);
    }

    inline std::shared_ptr<Expression> exclusive_or(const std::shared_ptr<Expression> &left,
                                                    const std::shared_ptr<Expression> &right) {
        return std::make_shared<ExclusiveOr>(left, right);
    }

    inline std::shared_ptr<Expression> equivalence(const std::shared_ptr<Expression> &left,
                                                   const std::shared_ptr<Expression> &right) {
        return std::make_shared<Equivalence>(left, right);
    }
}

#endif // EXPRESSION_FACTORY_H
