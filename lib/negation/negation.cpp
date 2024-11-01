#include "negation.h"

#include <expression_cast/expression_cast.h>
#include "expression_factory/expression_factory.h"

Negation::Negation(const std::shared_ptr<Expression> &expr) {
    if (const auto neg = ExpressionCast::as_negation(expr))
        this->expr = neg->expr;
    else
        this->expr = expr;
}

std::string Negation::toString() const {
    return "¬" + expr->toString();
}

bool Negation::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_neg = ExpressionCast::as_negation(other);
    return other_neg && expr->equals(other_neg->expr);
}

std::shared_ptr<Expression> Negation::toImplicationForm() const {
    return ExpressionFactory::negation(
        expr->toImplicationForm()
    );
}
