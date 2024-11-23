cmake_minimum_required(VERSION 3.10)
project(ProofSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib)

set(SOURCES
        src/main.cpp
        lib/expressions/expression/expression.h
        lib/expressions/variable/variable.cpp
        lib/expressions/variable/variable.h
        lib/expressions/implication/implication.cpp
        lib/expressions/implication/implication.h
        lib/expressions/negation/negation.cpp
        lib/expressions/negation/negation.h
        lib/proof/proof_engine/proof_engine.cpp
        lib/proof/proof_engine/proof_engine.h
        lib/expressions/conjunction/conjunction.cpp
        lib/expressions/conjunction/conjunction.h
        lib/expressions/disjunction/disjunction.cpp
        lib/expressions/disjunction/disjunction.h
        lib/expressions/exclusive_or/exclusive_or.cpp
        lib/expressions/exclusive_or/exclusive_or.h
        lib/expressions/expression_factory/expression_factory.h
        lib/expressions/expression_cast/expression_cast.h
        lib/inference_rules/inference_rule/inference_rule.h
        lib/inference_rules/modus_ponens/modus_ponens.cpp
        lib/inference_rules/modus_ponens/modus_ponens.h
        lib/proof/proof_context/proof_context.cpp
        lib/proof/proof_context/proof_context.h
        lib/substitution/substitution_context.cpp
        lib/substitution/substitution_context.h
        lib/expressions/equivalence/equivalence.cpp
        lib/expressions/equivalence/equivalence.h
        lib/proof/proof_logger/proof_logger.cpp
        lib/proof/proof_logger/proof_logger.h
        lib/proof/proof_logger/log_entity.h
        lib/inference_rules/inference_conclusion/inference_conclusion.h
        lib/parser/parser.cpp
        lib/inference_rules/inference_rule/inference_rule.cpp
        lib/inference_rules/modus_tollens/modus_tollens.h
        lib/inference_rules/modus_tollens/modus_tollens.cpp
        lib/inference_rules/disjunctive_syllogism/disjunctive_syllogism.h
        lib/inference_rules/disjunctive_syllogism/disjunctive_syllogism.cpp
        lib/inference_rules/hypothetic_syllogism/hypothetic_syllogism.h
        lib/inference_rules/hypothetic_syllogism/hypothetic_syllogism.cpp
        lib/inference_rules/separation_syllogism/separation_syllogism.h
        lib/inference_rules/separation_syllogism/separation_syllogism.cpp
)

add_executable(ProofSystem ${SOURCES})
