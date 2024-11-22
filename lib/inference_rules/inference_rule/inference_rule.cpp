#include "inference_rules/inference_rule/inference_rule.h"


InferenceConclusion InferenceRule::createConclusion(const std::shared_ptr<Expression> &statement,
                                                    const std::vector<int> &arguments,
                                                    const std::string &unification) const {
    return {statement, getCodeName(), arguments, unification};
}
