#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

#include "expressions/expression_factory/expression_factory.h"
#include "inference_rules/inference_rule/inference_rule.h"
#include "substitution/substitution_context.h"
#include "inference_rules/modus_ponens/modus_ponens.h"
#include "proof/proof_engine/proof_engine.h"


int main() {
    auto first = ExpressionFactory::implication(
        ExpressionFactory::variable("P"),
        ExpressionFactory::implication(
            ExpressionFactory::variable("Q"), ExpressionFactory::variable("P")
        )
    );
    auto second = ExpressionFactory::implication(
        ExpressionFactory::variable("P"),
        ExpressionFactory::implication(
            ExpressionFactory::variable("Q"), ExpressionFactory::variable("R")
        )
    );

    first->reindex(1);
    second->reindex(2);

    SubstitutionContext context;

    std::cout << context.unification(second, first) << std::endl;

    std::cout << context.toString();


    return 0;
}
