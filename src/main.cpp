#include <iostream>
#include <string>
#include "parser/parser.h"

int main() {
    std::string input;
    std::cout << "Введите логическое выражение: ";
    std::getline(std::cin, input);

    try {
        Parser parser(input);
        const auto expr = parser.parseExpression();
        std::cout << "Исходное выражение: " << expr->toString() << std::endl;

        const auto impl_form = expr->toImplicationForm();
        std::cout << "Импликационная форма: " << impl_form->toString() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
