#ifndef OR_H
#define OR_H

#include "expressions/expression/expression.h"
#include <memory>

class Disjunction final : public Expression {
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    Disjunction(const std::shared_ptr<Expression> &left, const std::shared_ptr<Expression> &right);

    [[nodiscard]] std::shared_ptr<Expression> getLeft() const {
        return left;
    }

    [[nodiscard]] std::shared_ptr<Expression> getRight() const {
        return right;
    }

    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] bool equals(const std::shared_ptr<Expression> &other) const override;

    [[nodiscard]] std::shared_ptr<Expression> toImplicationNegationForm() const override;

    bool match(const std::shared_ptr<Expression> &expression, SubstitutionContext &context) const override;

    [[nodiscard]] std::shared_ptr<Expression> substitute(SubstitutionContext &context) const override;

    void reindex(int id) override;

    [[nodiscard]] std::shared_ptr<Expression> clone() const override;
};

#endif // OR_H
