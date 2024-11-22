#include "proof_context.h"

#include "substitution/substitution_context.h"
#include "proof/proof_logger/log_entity.h"

ProofContext::ProofContext(const std::vector<std::shared_ptr<Expression> > &axioms,
                           const std::shared_ptr<Expression> &target): target(target) {
    for (const auto &axiom: axioms) {
        known.emplace_back(++current_step, axiom);
        visited.insert(axiom->toString());
        axiom->reindex(current_step);

        LogEntity entity;
        entity.statement = axiom->toString();
        logger.log(entity);
    }
}

bool ProofContext::addConclusionIfNew(const InferenceConclusion &conclusion) {
    conclusion.expression->reindex(0);
    const std::string repr = conclusion.expression->toString();
    if (visited.find(repr) != visited.end())
        return false;

    known.emplace_back(++current_step, conclusion.expression);
    visited.insert(repr);
    conclusion.expression->reindex(current_step);

    updated = true;

    LogEntity entity;
    entity.statement = conclusion.expression->toString();
    entity.inference_rule = conclusion.inference_rule_name;
    entity.inference_rule_arguments = conclusion.inference_rule_arguments;
    entity.substitution = conclusion.substitution;
    logger.log(entity);

    return true;
}

bool ProofContext::isTargetReached(const EnumeratedExpression &conclusion) {
    if (is_target_reached)
        return true;
    SubstitutionContext context;
    const bool is_unifiable = context.unification(target, conclusion.second);
    if (!is_unifiable)
        return false;
    if (!context.substituteIn(target)->equals(context.substituteIn(conclusion.second)))
        return false;

    is_target_reached = true;

    LogEntity entity;
    entity.statement = target->toString();
    entity.substitution = context.toString();
    entity.substitution_initial_expression = conclusion.first;
    logger.markAsUsed(logger.log(entity));
    return true;
}
