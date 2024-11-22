#include "modus_ponens.h"

#include "expressions/implication/implication.h"
#include "expressions/expression_cast/expression_cast.h"

#include "substitution/substitution_context.h"

#include <memory>

std::vector<InferenceConclusion> ModusPonens::apply(
    const std::vector<EnumeratedExpression> &knownStatements) const {
    std::vector<InferenceConclusion> conclusions;
    auto implications = findImplications(knownStatements);

    for (const auto &implication: implications)
        addMatchingConclusions(implication, knownStatements, conclusions);
    return conclusions;
}


std::vector<EnumeratedImplication> ModusPonens::findImplications(
    const std::vector<EnumeratedExpression> &statements) {
    std::vector<EnumeratedImplication> implications;
    for (const auto &[id, expression]: statements) {
        if (const auto implication = ExpressionCast::as_implication(expression)) {
            implications.emplace_back(id, implication);
        }
    }
    return implications;
}

void ModusPonens::addMatchingConclusions(const EnumeratedImplication &implication,
                                         const std::vector<EnumeratedExpression> &statements,
                                         std::vector<InferenceConclusion> &conclusions) const {
    SubstitutionContext context;
    for (const auto &[id, statement]: statements) {
        if (id == implication.first || usedPairs.find(std::make_pair(id, implication.first)) != usedPairs.end())
            continue;
        usedPairs.insert(std::make_pair(id, implication.first));

        context.clear();
        const bool is_unifiable = context.unification(implication.second->getAntecedent(), statement);
        if (!is_unifiable)
            continue;

        const auto unified = ExpressionCast::as_implication(context.substituteIn(implication.second));

        conclusions.push_back(createConclusion(unified->getConsequent(), std::vector{implication.first, id},
                                               context.toString()));
    }
}
