#ifndef VARIABLE_H
#define VARIABLE_H

#include <utility>

#include "expression/expression.h"

class Variable final : public Expression {
    std::string name;

public:
    explicit Variable(std::string name) : name(std::move(name)) {
    }

    [[nodiscard]] std::string toString() const override { return name; }

    [[nodiscard]] bool equals(const std::shared_ptr<Expression> &other) const override;
};

#endif // VARIABLE_H
