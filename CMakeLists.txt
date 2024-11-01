cmake_minimum_required(VERSION 3.10)
project(ProofSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib)

set(SOURCES
        src/main.cpp
        lib/expression/expression.cpp
        lib/expression/expression.h
        lib/variable/variable.cpp
        lib/variable/variable.h
        lib/implication/implication.cpp
        lib/implication/implication.h
        lib/negation/negation.cpp
        lib/negation/negation.h
        src/proof_engine/proof_engine.cpp
        src/proof_engine/proof_engine.h
        lib/and/and.cpp
        lib/and/and.h
        lib/or/or.cpp
        lib/or/or.h
        lib/xor/xor.cpp
        lib/xor/xor.h
        lib/expression_factory/expression_factory.h
        lib/expression_cast/expression_cast.h
)

add_executable(ProofSystem ${SOURCES})
