#ifndef AXIOM_SCHEME_H
#define AXIOM_SCHEME_H

#include "expressions/expression/expression.h"
#include <unordered_map>

class AxiomScheme {
    std::shared_ptr<Expression> schema;

public:
    explicit AxiomScheme(const std::shared_ptr<Expression> &schema) : schema(schema) {
    }

    [[nodiscard]] std::shared_ptr<Expression> generateExpression(
        const std::unordered_map<std::string, std::shared_ptr<Expression> > &mapping) const;

    bool matches(const std::shared_ptr<Expression> &expr,
                 std::unordered_map<std::string, std::shared_ptr<Expression> > &mapping) const;
};

#endif // AXIOM_SCHEME_H
