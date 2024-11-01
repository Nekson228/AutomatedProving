#include "and.h"
#include "negation/negation.h"

#include "expression_cast/expression_cast.h"
#include "expression_factory/expression_factory.h"

And::And(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right)
    : left(left), right(right) {
}

std::string And::toString() const {
    return "(" + left->toString() + " ∧ " + right->toString() + ")";
}

bool And::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_and = ExpressionCast::as_conjunction(other);
    return other_and && left->equals(other_and->left) && right->equals(other_and->right);
}

std::shared_ptr<Expression> And::toImplicationForm() const {
    // A ∧ B <=> ¬(A -> ¬B)
    return ExpressionFactory::negation(
        ExpressionFactory::implication(
            left->toImplicationForm(),
            ExpressionFactory::negation(right->toImplicationForm())
        )
    );
}
