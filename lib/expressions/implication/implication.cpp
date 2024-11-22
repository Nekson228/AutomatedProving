#include "implication.h"

#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"

std::string Implication::toString() const {
    return "(" + left->toString() + " -> " + right->toString() + ")";
}

bool Implication::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_impl = ExpressionCast::as_implication(other);
    return other_impl && left->equals(other_impl->left) && right->equals(other_impl->right);
}

std::shared_ptr<Expression> Implication::toImplicationNegationForm() const {
    return ExpressionFactory::implication(
        left->toImplicationNegationForm(),
        right->toImplicationNegationForm()
    );
}

std::shared_ptr<Expression> Implication::substitute(SubstitutionContext &context) const {
    return ExpressionFactory::implication(left->substitute(context), right->substitute(context));
}

void Implication::reindex(const int id) {
    left->reindex(id), right->reindex(id);
}

std::shared_ptr<Expression> Implication::clone() const {
    return ExpressionFactory::implication(left->clone(), right->clone());
}

bool Implication::match(const std::shared_ptr<Expression> &expression, SubstitutionContext &context) const {
    const auto implication = ExpressionCast::as_implication(expression);
    return implication && left->match(implication->left, context) && right->match(implication->right, context);
}
