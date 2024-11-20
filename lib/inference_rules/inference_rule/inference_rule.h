#ifndef INFERENCE_RULE_H
#define INFERENCE_RULE_H

#include "expressions/expression/expression.h"
#include <memory>
#include <vector>

class InferenceRule {
public:
    virtual ~InferenceRule() = default;

    [[nodiscard]] virtual std::vector<std::shared_ptr<Expression> > apply(
        const std::vector<std::shared_ptr<Expression> > &statements
    ) const = 0;
};

#endif // INFERENCE_RULE_H
