#ifndef VARIABLE_H
#define VARIABLE_H

#include <utility>

#include "expressions/expression/expression.h"

class Variable final : public Expression {
    std::string name;

public:
    explicit Variable(const std::string &name) : name(name + "0") {
    }

    [[nodiscard]] std::string toString() const override { return name; }

    [[nodiscard]] bool equals(const std::shared_ptr<Expression> &other) const override;

    [[nodiscard]] std::shared_ptr<Expression> toImplicationNegationForm() const override;

    bool match(const std::shared_ptr<Expression> &expression,
               SubstitutionContext &context) const override;

    [[nodiscard]] std::shared_ptr<Expression> substitute(
        SubstitutionContext &context) const override;

    void reindex(int id) override;
};

#endif // VARIABLE_H
