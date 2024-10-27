#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <memory>

class Expression {
public:
    virtual ~Expression() = default;
    [[nodiscard]] virtual std::string toString() const = 0;
    [[nodiscard]] virtual bool equals(const std::shared_ptr<Expression>& other) const = 0;
};

#endif // EXPRESSION_H
