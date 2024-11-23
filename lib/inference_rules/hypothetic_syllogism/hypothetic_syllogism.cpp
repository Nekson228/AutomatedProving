#include "hypothetic_syllogism.h"

#include "expressions/implication/implication.h"
#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"

#include "substitution/substitution_context.h"

#include <memory>

std::vector<InferenceConclusion> HypotheticSyllogism::apply(
        const std::vector<EnumeratedExpression> &knownStatements) const {
    std::vector<InferenceConclusion> conclusions;
    auto implications = findImplications(knownStatements);
    for (const auto &implication: implications)
        addMatchingConclusions(implication, implications, conclusions);
    return conclusions;
}


std::vector<EnumeratedImplication> HypotheticSyllogism::findImplications(
        const std::vector<EnumeratedExpression> &statements) {
    std::vector<EnumeratedImplication> implications;
    for (const auto &[id, expression]: statements) {
        if (const auto implication = ExpressionCast::as_implication(expression)) {
            implications.emplace_back(id, implication);
        }
    }
    return implications;
}

void HypotheticSyllogism::addMatchingConclusions(const EnumeratedImplication &implication,
                                                 std::vector<EnumeratedImplication> &statements,
                                          std::vector<InferenceConclusion> &conclusions) const {
    SubstitutionContext context;
    for (const auto &[id, statement]: statements) {
        if (id == implication.first || usedPairs.find(std::make_pair(id, implication.first)) != usedPairs.end())
            continue;
        usedPairs.insert(std::make_pair(id, implication.first));

        context.clear();
        const bool is_unifiable = context.unification(implication.second->getConsequent(), statement->getAntecedent());
        if (!is_unifiable)
            continue;

        const auto unified1 = ExpressionCast::as_implication(context.substituteIn(implication.second));
        const auto unified2 = ExpressionCast::as_implication(context.substituteIn(statement));

        const auto conclusion = ExpressionFactory::implication(implication.second->getAntecedent(), statement->getConsequent());

        conclusions.push_back(createConclusion(conclusion, std::vector{implication.first, id},
                                               context.toString()));
    }
}

