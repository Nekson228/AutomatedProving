#include "conjunction.h"
#include "expressions/negation/negation.h"

#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"

Conjunction::Conjunction(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right)
    : left(left), right(right) {
}

std::string Conjunction::toString() const {
    return "(" + left->toString() + " ∧ " + right->toString() + ")";
}

bool Conjunction::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_and = ExpressionCast::as_conjunction(other);
    return other_and && left->equals(other_and->left) && right->equals(other_and->right);
}

std::shared_ptr<Expression> Conjunction::toImplicationNegationForm() const {
    // A ∧ B <=> ¬(A -> ¬B)
    return ExpressionFactory::negation(
        ExpressionFactory::implication(
            left->toImplicationNegationForm(),
            ExpressionFactory::negation(right->toImplicationNegationForm())
        )
    );
}

std::shared_ptr<Expression> Conjunction::substitute(
    SubstitutionContext &context) const {
    return std::make_shared<Conjunction>(left->substitute(context), right->substitute(context));
}

void Conjunction::reindex(const int id) {
    left->reindex(id), right->reindex(id);
}

bool Conjunction::match(const std::shared_ptr<Expression> &expression,
                        SubstitutionContext &context) const {
    const auto conjunction = ExpressionCast::as_conjunction(expression);
    return conjunction && left->match(conjunction->left, context) && right->match(conjunction->right, context);
}
