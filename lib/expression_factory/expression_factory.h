#ifndef EXPRESSION_FACTORY_H
#define EXPRESSION_FACTORY_H

#include "implication/implication.h"
#include "negation/negation.h"
#include "variable/variable.h"
#include "and/and.h"
#include "or/or.h"
#include "xor/xor.h"
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
        return std::make_shared<And>(left, right);
    }

    inline std::shared_ptr<Expression> disjunction(const std::shared_ptr<Expression> &left,
                                                   const std::shared_ptr<Expression> &right) {
        return std::make_shared<Or>(left, right);
    }

    inline std::shared_ptr<Expression> exclusive_or(const std::shared_ptr<Expression> &left,
                                                    const std::shared_ptr<Expression> &right) {
        return std::make_shared<Xor>(left, right);
    }
} // namespace ExpressionFactory

#endif // EXPRESSION_FACTORY_H
