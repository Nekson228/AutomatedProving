#ifndef NEGATION_H
#define NEGATION_H

#include "expression/expression.h"

class Negation final : public Expression {
    std::shared_ptr<Expression> expr;

public:
    explicit Negation(const std::shared_ptr<Expression> &expr);

    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] bool equals(const std::shared_ptr<Expression> &other) const override;

    [[nodiscard]] std::shared_ptr<Expression> toImplicationForm() const override;
};

#endif // NEGATION_H
