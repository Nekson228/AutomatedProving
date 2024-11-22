#include "disjunctive_syllogism.h"

#include "expressions/disjunction/disjunction.h"
#include "expressions/expression_cast/expression_cast.h"
#include "substitution/substitution_context.h"

#include <memory>

std::vector<InferenceConclusion> DisjunctiveSyllogism::apply(
        const std::vector<EnumeratedExpression> &knownStatements) const {
    std::vector<InferenceConclusion> conclusions;
    auto disjunctions = findDisjunction(knownStatements);
    for (const auto &disjunction: disjunctions)
        addMatchingConclusions(disjunction, knownStatements, conclusions);
    return conclusions;
}


std::vector<EnumeratedDisjunction> DisjunctiveSyllogism::findDisjunction(
        const std::vector<EnumeratedExpression> &statements) {
    std::vector<EnumeratedDisjunction> disjunctions;
    for (const auto &[id, expression]: statements) {
        if (const auto disjunction = ExpressionCast::as_disjunction(expression)) {
            disjunctions.emplace_back(id, disjunction);
        }
    }
    return disjunctions;
}

void DisjunctiveSyllogism::addMatchingConclusions(const EnumeratedDisjunction &disjunction,
                                          const std::vector<EnumeratedExpression> &statements,
                                          std::vector<InferenceConclusion> &conclusions) const {
    SubstitutionContext context;
    for (const auto &[id, statement]: statements) {
        if (id == disjunction.first || usedPairs.find(std::make_pair(id, disjunction.first)) != usedPairs.end())
            continue;
        usedPairs.insert(std::make_pair(id, disjunction.first));
        const auto negative = ExpressionCast::as_negation(statement);
        if (negative == nullptr)
            continue;
        context.clear();
        const bool is_unifiable = context.unification(disjunction.second->getLeft(), negative->getInnerExpression());
        if (!is_unifiable)
            continue;

        const auto unified = ExpressionCast::as_disjunction(context.substituteIn(disjunction.second));

        conclusions.push_back(createConclusion(unified->getRight(), std::vector{disjunction.first, id},
                                               context.toString()));
    }
}
