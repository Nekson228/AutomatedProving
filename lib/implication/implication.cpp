#include "implication.h"

#include "expression_cast/expression_cast.h"
#include "expression_factory/expression_factory.h"

std::string Implication::toString() const {
    return "(" + left->toString() + " -> " + right->toString() + ")";
}

bool Implication::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_impl = ExpressionCast::as_implication(other);
    return other_impl && left->equals(other_impl->left) && right->equals(other_impl->right);
}

std::shared_ptr<Expression> Implication::toImplicationForm() const {
    return ExpressionFactory::implication(
        left->toImplicationForm(),
        right->toImplicationForm()
    );
}
