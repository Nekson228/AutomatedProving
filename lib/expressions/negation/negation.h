#ifndef NEGATION_H
#define NEGATION_H

#include "expressions/expression/expression.h"

class Negation final : public Expression {
    std::shared_ptr<Expression> expr;

public:
    explicit Negation(const std::shared_ptr<Expression> &expr);

    [[nodiscard]] std::shared_ptr<Expression> getInnerExpression() const;

    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] bool equals(const std::shared_ptr<Expression> &other) const override;

    [[nodiscard]] std::shared_ptr<Expression> toImplicationNegationForm() const override;

    bool match(const std::shared_ptr<Expression> &expression, SubstitutionContext &context) const override;

    [[nodiscard]] std::shared_ptr<Expression> substitute(SubstitutionContext &context) const override;

    void reindex(int id) override;

    [[nodiscard]] std::shared_ptr<Expression> clone() const override;
};

#endif // NEGATION_H
