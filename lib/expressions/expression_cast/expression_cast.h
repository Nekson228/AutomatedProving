#ifndef EXPRESSION_CAST_H
#define EXPRESSION_CAST_H

#include "expressions/implication/implication.h"
#include "expressions/negation/negation.h"
#include "expressions/conjunction/conjunction.h"
#include "expressions/disjunction/disjunction.h"
#include "expressions/exclusive_or/exclusive_or.h"
#include "expressions/variable/variable.h"
#include "expressions/equivalence/equivalence.h"
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


    inline std::shared_ptr<Conjunction> as_conjunction(const std::shared_ptr<Expression> &expr) {
        return std::dynamic_pointer_cast<Conjunction>(expr);
    }

    inline std::shared_ptr<Disjunction> as_disjunction(const std::shared_ptr<Expression> &expr) {
        return std::dynamic_pointer_cast<Disjunction>(expr);
    }

    inline std::shared_ptr<ExclusiveOr> as_exclusive_or(const std::shared_ptr<Expression> &expr) {
        return std::dynamic_pointer_cast<ExclusiveOr>(expr);
    }

    inline std::shared_ptr<Equivalence> as_equivalence(const std::shared_ptr<Expression> &expr) {
        return std::dynamic_pointer_cast<Equivalence>(expr);
    }
}


#endif
