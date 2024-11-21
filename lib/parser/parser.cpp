#include "parser.h"
#include <cctype>
#include <stdexcept>
#include "expression_factory/expression_factory.h"

Parser::Parser(const std::string &input) : input(input) {}

std::shared_ptr<Expression> Parser::parseExpression() {
    auto expr = parseImplies();
    skipWhitespace();
    if (pos != input.size() && peek() != ')') {
        throw std::runtime_error("An unexpected symbol:" + std::string(1, peek()));
    }
    return expr;
}


char Parser::peek() const {
    return (pos < input.size()) ? input[pos] : '\0';
}

char Parser::get() {
    return (pos < input.size()) ? input[pos++] : '\0';
}

void Parser::skipWhitespace() {
    while (isspace(peek())) {
        get();
    }
}

std::shared_ptr<Expression> Parser::parseVariable() {
    skipWhitespace();
    if (peek() == '(') {
        get();
        auto expr = parseExpression();
        skipWhitespace();
        if (peek() != ')') {
            throw std::runtime_error("A closing parenthesis was expected");
        }
        get();
        return expr;
    }
    if (isalpha(peek())) {
        std::string name(1, get());
        return ExpressionFactory::variable(name);
    }
    throw std::runtime_error("A variable or an opening parenthesis was expected");
}


std::shared_ptr<Expression> Parser::parseNegation() {
    skipWhitespace();
    if (peek() == '!') {
        get();
        return ExpressionFactory::negation(parseNegation());
    }
    return parseVariable();
}

std::shared_ptr<Expression> Parser::parseAnd() {
    auto left = parseNegation();
    skipWhitespace();
    while (peek() == '*') {
        get();
        auto right = parseNegation();
        left = ExpressionFactory::conjunction(left, right);
        skipWhitespace();
    }
    return left;
}

std::shared_ptr<Expression> Parser::parseOr() {
    auto left = parseAnd();
    skipWhitespace();
    while (peek() == '|') {
        get();
        auto right = parseAnd();
        left = ExpressionFactory::disjunction(left, right);
        skipWhitespace();
    }
    return left;
}

std::shared_ptr<Expression> Parser::parseImplies() {
    auto left = parseXor();
    skipWhitespace();
    if (peek() == '>') {
        get();
        auto right = parseImplies();
        return ExpressionFactory::implication(left, right);
    }
    return left;
}

std::shared_ptr<Expression> Parser::parseXor() {
    auto left = parseEquivalent();
    skipWhitespace();
    while (peek() == '+') {
        get();
        auto right = parseEquivalent();
        left = ExpressionFactory::exclusive_or(left, right);
        skipWhitespace();
    }
    return left;
}

std::shared_ptr<Expression> Parser::parseEquivalent() {
    auto left = parseOr();
    skipWhitespace();
    while (peek() == '=') {
        get();
        auto right = parseOr();
        left = ExpressionFactory::equivalence(left, right);
        skipWhitespace();
    }
    return left;
}
