#include "xor.h"
#include "and/and.h"

#include <expression_cast/expression_cast.h>
#include <expression_factory/expression_factory.h>

Xor::Xor(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right)
    : left(left), right(right) {
}

std::string Xor::toString() const {
    return "(" + left->toString() + " ⊕ " + right->toString() + ")";
}

bool Xor::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_xor = ExpressionCast::as_xor(other);
    return other_xor && left->equals(other_xor->left) && right->equals(other_xor->right);
}

std::shared_ptr<Expression> Xor::toImplicationForm() const {
    // A ⊕ B === (A ∨ B) ∧ ¬(A ∧ B)
    const auto result = ExpressionFactory::conjunction(
        ExpressionFactory::disjunction(left, right),
        ExpressionFactory::negation(
            ExpressionFactory::conjunction(left, right)
        )
    );
    return result->toImplicationForm();
}
