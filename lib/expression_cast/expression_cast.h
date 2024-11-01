#ifndef EXPRESSION_CAST_H
#define EXPRESSION_CAST_H

#include "implication/implication.h"
#include "negation/negation.h"
#include "and/and.h"
#include "or/or.h"
#include "xor/xor.h"
#include "variable/variable.h"
#include <memory>

namespace ExpressionCast {
    inline std::shared_ptr<Negation> as_negation(const std::shared_ptr<Expression> &expr) {
        return std::dynamic_pointer_cast<Negation>(expr);
    }


    inline std::shared_ptr<Implication> as_implication(const std::shared_ptr<Expression> &expr) {
        return std::dynamic_pointer_cast<Implication>(expr);
    }


    inline std::shared_ptr<Variable> as_variable(const std::shared_ptr<Expression> &expr) {
        return std::dynamic_pointer_cast<Variable>(expr);
    }


    inline std::shared_ptr<And> as_conjunction(const std::shared_ptr<Expression> &expr) {
        return std::dynamic_pointer_cast<And>(expr);
    }

    inline std::shared_ptr<Or> as_disjunction(const std::shared_ptr<Expression> &expr) {
        return std::dynamic_pointer_cast<Or>(expr);
    }

    inline std::shared_ptr<Xor> as_xor(const std::shared_ptr<Expression> &expr) {
        return std::dynamic_pointer_cast<Xor>(expr);
    }
}


#endif
