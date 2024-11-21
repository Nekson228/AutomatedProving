#ifndef XOR_H
#define XOR_H

#include "expressions/expression/expression.h"
#include <memory>

class ExclusiveOr final : public Expression {
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    ExclusiveOr(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right);

    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] bool equals(const std::shared_ptr<Expression> &other) const override;

    [[nodiscard]] std::shared_ptr<Expression> toImplicationNegationForm() const override;

    bool match(const std::shared_ptr<Expression> &expression,
               SubstitutionContext &context) const override;

    [[nodiscard]] std::shared_ptr<Expression> substitute(
        SubstitutionContext &context) const override;

    void reindex(int id) override;
};

#endif // XOR_H
