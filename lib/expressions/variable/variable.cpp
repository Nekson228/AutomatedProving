#include "variable.h"

#include "expressions/expression/expression.h"
#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"

#include "substitution/substitution_context.h"

std::string Variable::getBareVariableName() const {
    // assuming a variable name is a single letter
    return name.substr(0, 1);
}

std::string Variable::getVariableId() const {
    // assuming a variable name is a single letter
    return name.substr(1, name.size() - 1);
}

bool Variable::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_var = ExpressionCast::as_variable(other);
    return other_var && other_var->name == name;
}

std::shared_ptr<Expression> Variable::toImplicationNegationForm() const {
    return ExpressionFactory::variable(getBareVariableName());
}

bool Variable::match(const std::shared_ptr<Expression> &expression, SubstitutionContext &context) const {
    return context.addIfPossible(name, expression);
}

std::shared_ptr<Expression> Variable::substitute(SubstitutionContext &context) const {
    if (context.contains(name))
        return context.get(name);
    return clone();
}

void Variable::reindex(const int id) {
    name = getBareVariableName() + std::to_string(id);
}

std::shared_ptr<Expression> Variable::clone() const {
    return ExpressionFactory::variable(getBareVariableName(), getVariableId());
}
