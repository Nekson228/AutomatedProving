#ifndef MODUS_PONENS_H
#define MODUS_PONENS_H

#include "inference_rules/inference_rule/inference_rule.h"
#include "expressions/expression_cast/expression_cast.h"
#include <vector>
#include <memory>

class ModusPonens final : public InferenceRule {
    [[nodiscard]] static std::vector<std::shared_ptr<Implication> > findImplications(
        const std::vector<std::shared_ptr<Expression> > &statements
    );

    [[nodiscard]] static bool matchesAntecedent(
        const std::shared_ptr<Implication> &implication,
        const std::vector<std::shared_ptr<Expression> > &statements
    );

    static void addConclusions(
        std::vector<std::shared_ptr<Expression> > &conclusions,
        const std::shared_ptr<Implication> &implication
    );

public:
    [[nodiscard]] std::vector<std::shared_ptr<Expression> > apply(
        const std::vector<std::shared_ptr<Expression> > &knownStatements
    ) const override;
};

#endif // MODUS_PONENS_H
