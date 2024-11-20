#include "substitution_context.h"

bool SubstitutionContext::add_if_possible(const std::string &name, const std::shared_ptr<Expression> &expr) {
    const auto it = mapping.find(name);
    if (it != mapping.end()) {
        return it->second->equals(expr);
    }
    mapping[name] = expr;
    return true;
}

std::shared_ptr<Expression> SubstitutionContext::apply(const std::shared_ptr<Expression> &expr) {
    return expr->substitute(*this);
}

bool SubstitutionContext::unification(const std::shared_ptr<Expression> &expr1,
                                      const std::shared_ptr<Expression> &expr2) {
    return expr1->match(expr2, *this);
}

std::string SubstitutionContext::toString() const {
    std::string result;
    for (const auto &[name, expr]: mapping) {
        result += name + " -> " + expr->toString() + "\n";
    }
    return result;
}
