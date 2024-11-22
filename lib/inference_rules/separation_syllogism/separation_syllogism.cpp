#include "separation_syllogism.h"

#include "expressions/implication/implication.h"
#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"


#include "substitution/substitution_context.h"

#include <memory>

std::vector<InferenceConclusion> SeparationSyllogism::apply(
        const std::vector<EnumeratedExpression> &knownStatements) const {
    std::vector<InferenceConclusion> conclusions;
    auto exclusives_ors = findExclusivesOrs(knownStatements);

    for (const auto &exclusive_or: exclusives_ors)
        addMatchingConclusions(exclusive_or, knownStatements, conclusions);
    return conclusions;
}


std::vector<EnumeratedExclusiveOr> SeparationSyllogism::findExclusivesOrs(
        const std::vector<EnumeratedExpression> &statements) {
    std::vector<EnumeratedExclusiveOr> exclusive_ors;
    for (const auto &[id, expression]: statements) {
        if (const auto exclusive_or = ExpressionCast::as_exclusive_or(expression)) {
            exclusive_ors.emplace_back(id, exclusive_or);
        }
    }
    return exclusive_ors;
}

void SeparationSyllogism::addMatchingConclusions(const EnumeratedExclusiveOr &exclusive_or,
                                         const std::vector<EnumeratedExpression> &statements,
                                         std::vector<InferenceConclusion> &conclusions) const {
    SubstitutionContext context;
    for (const auto &[id, statement]: statements) {
        if (id == exclusive_or.first || usedPairs.find(std::make_pair(id, exclusive_or.first)) != usedPairs.end())
            continue;
        usedPairs.insert(std::make_pair(id, exclusive_or.first));

        context.clear();
        const bool is_unifiable = context.unification(exclusive_or.second->getLeft(), statement);
        if (!is_unifiable)
            continue;

        const auto unified = ExpressionCast::as_exclusive_or(context.substituteIn(exclusive_or.second));

        conclusions.push_back(createConclusion(ExpressionFactory::negation(unified->getRight()), std::vector{exclusive_or.first, id},
                                               context.toString()));
    }
}
