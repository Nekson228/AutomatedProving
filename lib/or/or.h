#ifndef OR_H
#define OR_H

#include "expression/expression.h"
#include <memory>

class Or final : public Expression {
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    Or(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right);

    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] bool equals(const std::shared_ptr<Expression> &other) const override;

    [[nodiscard]] std::shared_ptr<Expression> toImplicationForm() const override;
};

#endif // OR_H
