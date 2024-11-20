#include "variable.h"

#include "expressions/expression/expression.h"
#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"

#include "substitution/substitution_context.h"

bool Variable::equals(const std::shared_ptr<Expression> &other) const {
    const auto other_var = ExpressionCast::as_variable(other);
    return other_var && other_var->name == name;
}

std::shared_ptr<Expression> Variable::toImplicationNegationForm() const {
    return ExpressionFactory::variable(name);
}

bool Variable::match(const std::shared_ptr<Expression> &expression,
                     SubstitutionContext &context) const {
    return context.add_if_possible(name, expression);
}

std::shared_ptr<Expression> Variable::substitute(
    SubstitutionContext &context) const {
    if (context.contains(name)) {
        return context.get(name);
    }
    return ExpressionFactory::variable(name);
}

void Variable::reindex(const int id) {
    name = name.substr(0, name.size() - 1) + std::to_string(id);
}
