#include "variable.h"

bool Variable::equals(const std::shared_ptr<Expression>& other) const {
    const auto other_var = std::dynamic_pointer_cast<Variable>(other);
    return other_var && other_var->name == name;
}
