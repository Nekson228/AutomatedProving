#ifndef EQUIVALENCE_H
#define EQUIVALENCE_H

#include "expressions/expression/expression.h"


class Equivalence final : public Expression {
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    Equivalence(const std::shared_ptr<Expression> &left,
                const std::shared_ptr<Expression> &right): left(left), right(right) {
    }

    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] bool equals(const std::shared_ptr<Expression> &other) const override;

    [[nodiscard]] std::shared_ptr<Expression> toImplicationNegationForm() const override;

    bool match(const std::shared_ptr<Expression> &expression,
               SubstitutionContext &context) const override;

    [[nodiscard]] std::shared_ptr<Expression> substitute(SubstitutionContext &context) const override;

    void reindex(int id) override;
};


#endif //EQUIVALENCE_H
