#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <memory>
#include <unordered_map>

class SubstitutionContext;

class Expression {
public:
    virtual ~Expression() = default;

    [[nodiscard]] virtual std::string toString() const = 0;

    [[nodiscard]] virtual bool equals(const std::shared_ptr<Expression> &other) const = 0;

    [[nodiscard]] virtual std::shared_ptr<Expression> toImplicationNegationForm() const = 0;

    virtual bool match(const std::shared_ptr<Expression> &expression, SubstitutionContext &context) const = 0;

    [[nodiscard]] virtual std::shared_ptr<Expression> substitute(SubstitutionContext &context) const = 0;

    virtual void reindex(int id) = 0;

    [[nodiscard]] virtual std::shared_ptr<Expression> clone() const = 0;
};

#endif // EXPRESSION_H
