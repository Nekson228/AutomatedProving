#ifndef AND_H
#define AND_H

#include "expression/expression.h"
#include <memory>

class And final : public Expression {
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    And(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right);

    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] bool equals(const std::shared_ptr<Expression> &other) const override;

    [[nodiscard]] std::shared_ptr<Expression> toImplicationForm() const override;
};

#endif // AND_H
