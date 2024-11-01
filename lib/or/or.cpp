#include "or.h"
#include "negation/negation.h"

#include <expression_cast/expression_cast.h>
#include <expression_factory/expression_factory.h>


Or::Or(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right)
    : left(left), right(right) {
}

std::string Or::toString() const {
    return "(" + left->toString() + " ∨ " + right->toString() + ")";
}

bool Or::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_or = ExpressionCast::as_disjunction(other);
    return other_or && left->equals(other_or->left) && right->equals(other_or->right);
}

std::shared_ptr<Expression> Or::toImplicationForm() const {
    // A ∨ B <=> ¬A → B
    return ExpressionFactory::implication(
        ExpressionFactory::negation(left->toImplicationForm()),
        right->toImplicationForm()
    );
}
