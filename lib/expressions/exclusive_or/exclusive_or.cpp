#include "exclusive_or.h"
#include "expressions/conjunction/conjunction.h"

#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"

ExclusiveOr::ExclusiveOr(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right)
    : left(left), right(right) {
}

std::string ExclusiveOr::toString() const {
    return "(" + left->toString() + " ⊕ " + right->toString() + ")";
}

bool ExclusiveOr::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_xor = ExpressionCast::as_exclusive_or(other);
    return other_xor && left->equals(other_xor->left) && right->equals(other_xor->right);
}

std::shared_ptr<Expression> ExclusiveOr::toImplicationNegationForm() const {
    // A ⊕ B <=> (A ∨ B) ∧ ¬(A ∧ B)
    const auto result = ExpressionFactory::conjunction(
        ExpressionFactory::disjunction(left, right),
        ExpressionFactory::negation(
            ExpressionFactory::conjunction(left, right)
        )
    );
    return result->toImplicationNegationForm();
}

std::shared_ptr<Expression> ExclusiveOr::substitute(
    SubstitutionContext &context) const {
    return std::make_shared<ExclusiveOr>(left->substitute(context), right->substitute(context));
}

void ExclusiveOr::reindex(const int id) {
    left->reindex(id), right->reindex(id);
}

bool ExclusiveOr::match(const std::shared_ptr<Expression> &expression,
                        SubstitutionContext &context) const {
    const auto exclusive_or = ExpressionCast::as_exclusive_or(expression);
    return exclusive_or && left->match(exclusive_or->left, context) && right->match(exclusive_or->right, context);
}
