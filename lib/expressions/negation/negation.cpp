#include "negation.h"

#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"

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

std::shared_ptr<Expression> Negation::toImplicationNegationForm() const {
    return ExpressionFactory::negation(
        expr->toImplicationNegationForm()
    );
}

std::shared_ptr<Expression> Negation::substitute(SubstitutionContext &context) const {
    return ExpressionFactory::negation(expr->substitute(context));
}

void Negation::reindex(const int id) {
    expr->reindex(id);
}

std::shared_ptr<Expression> Negation::clone() const {
    return ExpressionFactory::negation(expr->clone());
}

bool Negation::match(const std::shared_ptr<Expression> &expression, SubstitutionContext &context) const {
    const auto negation = ExpressionCast::as_negation(expression);
    return negation && expression->match(negation->expr, context);
}

std::shared_ptr<Expression> Negation::getInnerExpression() const {
    return expr;
}
