// parser.h
#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <string>
#include "expression/expression.h"

class Parser {
    std::string input;
    size_t pos = 0;

public:
    explicit Parser(const std::string &input);

    std::shared_ptr<Expression> parseExpression();

private:
    char peek() const;
    char get();
    void skipWhitespace();
    std::shared_ptr<Expression> parseVariable();
    std::shared_ptr<Expression> parseNegation();
    std::shared_ptr<Expression> parseAnd();
    std::shared_ptr<Expression> parseOr();
    std::shared_ptr<Expression> parseImplies();
    std::shared_ptr<Expression> parseXor();
    std::shared_ptr<Expression> parseEquivalent();
};

#endif // PARSER_H
