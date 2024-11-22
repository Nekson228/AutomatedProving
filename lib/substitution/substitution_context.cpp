#include "substitution_context.h"

#include <sstream>

bool SubstitutionContext::addIfPossible(const std::string &name, const std::shared_ptr<Expression> &expr) {
    const auto it = mapping.find(name);
    if (it != mapping.end()) {
        return it->second->equals(expr);
    }
    mapping[name] = expr->clone();
    return true;
}

std::shared_ptr<Expression> SubstitutionContext::substituteIn(const std::shared_ptr<Expression> &expr) {
    return expr->substitute(*this);
}

bool SubstitutionContext::unification(const std::shared_ptr<Expression> &expr1,
                                      const std::shared_ptr<Expression> &expr2) {
    if (expr1->match(expr2, *this))
        return true;
    clear();
    return expr2->match(expr1, *this);
}

std::string SubstitutionContext::toString() const {
    std::stringstream ss;
    ss << '{';
    for (auto it = mapping.begin(); it != mapping.end(); ++it) {
        ss << it->first << " -> " << it->second->toString();
        if (std::next(it) != mapping.end())
            ss << "; ";
    }
    ss << '}';
    return ss.str();
}
