#include "implication.h"

std::string Implication::toString() const {
    return "(" + left->toString() + " -> " + right->toString() + ")";
}

bool Implication::equals(const std::shared_ptr<Expression>& other) const {

    const auto other_impl = std::dynamic_pointer_cast<Implication>(other);
    return other_impl && left->equals(other_impl->left) && right->equals(other_impl->right);
}


