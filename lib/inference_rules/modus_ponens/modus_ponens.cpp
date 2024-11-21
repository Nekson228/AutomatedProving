#include "modus_ponens.h"

#include <algorithm>

#include "expressions/implication/implication.h"
#include "expressions/expression_cast/expression_cast.h"

#include <memory>

std::vector<std::shared_ptr<Expression> > ModusPonens::apply(
    const std::vector<std::shared_ptr<Expression> > &knownStatements) const {
    std::vector<std::shared_ptr<Expression> > conclusions;
    auto implications = findImplications(knownStatements);

    for (const auto &implication: implications)
        if (matchesAntecedent(implication, knownStatements))
            addConclusions(conclusions, implication);
    return conclusions;
}


std::vector<std::shared_ptr<Implication> > ModusPonens::findImplications(
    const std::vector<std::shared_ptr<Expression> > &statements) {
    std::vector<std::shared_ptr<Implication> > implications;
    for (const auto &statement: statements) {
        if (const auto implication = ExpressionCast::as_implication(statement)) {
            implications.push_back(implication);
        }
    }
    return implications;
}

bool ModusPonens::matchesAntecedent(const std::shared_ptr<Implication> &implication,
                                    const std::vector<std::shared_ptr<Expression> > &statements) {
    return std::find(statements.begin(), statements.end(), implication->getAntecedent()) != statements.end();
}

void ModusPonens::addConclusions(std::vector<std::shared_ptr<Expression> > &conclusions,
                                 const std::shared_ptr<Implication> &implication) {
    conclusions.push_back(implication->getConsequent());
}
