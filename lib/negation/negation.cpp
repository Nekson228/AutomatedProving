#include "negation.h"

std::string Negation::toString() const {
    return "¬" + expr->toString();
}

bool Negation::equals(const std::shared_ptr<Expression>& other) const {
    const auto other_neg = std::dynamic_pointer_cast<Negation>(other);
    return other_neg && expr->equals(other_neg->expr);
}
