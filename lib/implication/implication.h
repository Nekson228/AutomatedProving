#ifndef IMPLICATION_H
#define IMPLICATION_H

#include "expression/expression.h"

class Implication final : public Expression {
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    Implication(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right)
        : left(left), right(right) {
    }

    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] bool equals(const std::shared_ptr<Expression> &other) const override;

    [[nodiscard]] std::shared_ptr<Expression> toImplicationForm() const override;
};

#endif // IMPLICATION_H
