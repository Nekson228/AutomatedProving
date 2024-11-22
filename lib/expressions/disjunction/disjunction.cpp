#include "disjunction.h"
#include "expressions/negation/negation.h"

#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"


Disjunction::Disjunction(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right)
    : left(left), right(right) {
}

std::string Disjunction::toString() const {
    return "(" + left->toString() + " ∨ " + right->toString() + ")";
}

bool Disjunction::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_or = ExpressionCast::as_disjunction(other);
    return other_or && left->equals(other_or->left) && right->equals(other_or->right);
}

std::shared_ptr<Expression> Disjunction::toImplicationNegationForm() const {
    // A ∨ B <=> ¬A → B
    return ExpressionFactory::implication(
        ExpressionFactory::negation(left->toImplicationNegationForm()),
        right->toImplicationNegationForm()
    );
}

std::shared_ptr<Expression> Disjunction::substitute(
    SubstitutionContext &context) const {
    return std::make_shared<Disjunction>(left->substitute(context), right->substitute(context));
}

void Disjunction::reindex(const int id) {
    left->reindex(id), right->reindex(id);
}

std::shared_ptr<Expression> Disjunction::clone() const {
    return ExpressionFactory::disjunction(left->clone(), right->clone());
}

bool Disjunction::match(const std::shared_ptr<Expression> &expression,
                        SubstitutionContext &context) const {
    const auto disjunction = ExpressionCast::as_disjunction(expression);
    return disjunction && left->match(disjunction->left, context) && right->match(disjunction->right, context);
}
