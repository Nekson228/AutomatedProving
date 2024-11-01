#include "variable.h"

#include <expression_cast/expression_cast.h>
#include <expression_factory/expression_factory.h>

bool Variable::equals(const std::shared_ptr<Expression>& other) const {
    const auto other_var = ExpressionCast::as_variable(other);
    return other_var && other_var->name == name;
}

std::shared_ptr<Expression> Variable::toImplicationForm() const {
    return ExpressionFactory::variable(name);
}
