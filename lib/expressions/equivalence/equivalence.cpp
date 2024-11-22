#include "equivalence.h"

#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"

std::string Equivalence::toString() const {
    return "(" + left->toString() + " ≡ " + right->toString() + ")";
}

bool Equivalence::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_eq = ExpressionCast::as_equivalence(other);
    return other_eq && left->equals(other_eq->left) && right->equals(other_eq->right);
}

std::shared_ptr<Expression> Equivalence::toImplicationNegationForm() const {
    // (A ≡ B) = (A → B) ∧ (B → A)
    return ExpressionFactory::conjunction(
        ExpressionFactory::implication(left, right),
        ExpressionFactory::implication(right, left)
    )->toImplicationNegationForm();
}

bool Equivalence::match(const std::shared_ptr<Expression> &expression, SubstitutionContext &context) const {
    const auto equivalence = ExpressionCast::as_equivalence(expression);
    return equivalence && left->match(equivalence->left, context) && right->match(equivalence->right, context);
}

std::shared_ptr<Expression> Equivalence::substitute(SubstitutionContext &context) const {
    return ExpressionFactory::equivalence(left->substitute(context), right->substitute(context));
}

void Equivalence::reindex(const int id) {
    left->reindex(id), right->reindex(id);
}

std::shared_ptr<Expression> Equivalence::clone() const {
    return ExpressionFactory::equivalence(left->clone(), right->clone());
}
