#include <iostream>
#include <memory>

#include "expression_factory/expression_factory.h"


int main() {
    const auto expr =
            ExpressionFactory::exclusive_or(
                ExpressionFactory::variable("A"),
                ExpressionFactory::variable("B")
            );
    std::cout << expr->toString() << std::endl;

    const auto impl_form = expr->toImplicationForm();
    std::cout << impl_form->toString() << std::endl;
    return 0;
}
