#include "parser.h"
#include <cctype>
#include <stdexcept>
#include "expression_factory/expression_factory.h"

Parser::Parser(const std::string &input) : input(input) {}

std::shared_ptr<Expression> Parser::parseExpression() {
    auto expr = parseImplies();
    skipWhitespace();
    if (pos != input.size()) {
        throw std::runtime_error("Неожиданный символ: " + std::string(1, peek()));
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
    if (isalpha(peek())) {
        std::string name(1, get());
        return ExpressionFactory::variable(name);
    }
    throw std::runtime_error("Ожидалась переменная");
}

std::shared_ptr<Expression> Parser::parseNegation() {
    skipWhitespace();
    if (peek() == '!') {
        get();
        return ExpressionFactory::negation(parseNegation());
    }
    return parseVariable(); // Если не отрицание, ожидаем переменную
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
        //left = ExpressionFactory::equivalent(left, right);
        skipWhitespace();
    }
    return left;
}
