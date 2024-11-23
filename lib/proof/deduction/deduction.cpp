#include "deduction.h"

Deduction::Deduction(const std::shared_ptr<Expression> &target): target(target) {
    statements.push_back(target);
}
