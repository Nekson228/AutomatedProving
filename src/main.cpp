#include <iostream>

#include <memory>
#include <vector>

#include "parser/parser.h"
#include "inference_rules/modus_ponens/modus_ponens.h"
#include "proof/proof_engine/proof_engine.h"
#include "proof/proof_context/proof_context.h"

int main() {
    const auto a1 = Parser("a>(b>a)").parseExpression(),
            a2 = Parser("(a>(b>c))>((a>b)>(a>c))").parseExpression(),
            a3 = Parser("((!b>!a)>((!b>a)>b))").parseExpression();
    const auto axioms = std::vector{a1, a2, a3};

    const auto target = Parser("a>a").parseExpression()->toImplicationNegationForm();

    std::cout << "Target: " << target->toString() << std::endl;

    ProofContext context(axioms, target);
    const ProofEngine engine(axioms, {std::make_shared<ModusPonens>()});

    std::cout << (engine.prove(context) ? ":)" : ":(") << std::endl;

    context.getLogger().printUsedTheorems(std::cout);

    return 0;
}
