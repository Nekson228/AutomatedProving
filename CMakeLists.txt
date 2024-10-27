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
        lib/proof_engine/proof_engine.cpp
        lib/proof_engine/proof_engine.h
)

add_executable(ProofSystem ${SOURCES})
