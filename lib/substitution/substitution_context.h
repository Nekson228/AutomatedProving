#ifndef SUBSTITUTION_CONTEXT_H
#define SUBSTITUTION_CONTEXT_H

#include <unordered_map>
#include <memory>
#include <string>

#include "expressions/expression/expression.h"


class SubstitutionContext {
    std::unordered_map<std::string, std::shared_ptr<Expression> > mapping;

public:
    [[nodiscard]] std::string toString() const;

    bool add_if_possible(const std::string &name, const std::shared_ptr<Expression> &expr);

    void clear() { mapping.clear(); }

    [[nodiscard]] bool contains(const std::string &name) const { return mapping.find(name) != mapping.end(); }

    [[nodiscard]] std::shared_ptr<Expression> get(const std::string &name) const { return mapping.at(name); }

    [[nodiscard]] std::shared_ptr<Expression> apply(const std::shared_ptr<Expression> &expr);

    [[nodiscard]] bool unification(const std::shared_ptr<Expression> &expr1,
                                   const std::shared_ptr<Expression> &expr2);
};


#endif //SUBSTITUTION_CONTEXT_H
