#ifndef DEDUCTION_H
#define DEDUCTION_H

#include <vector>

#include "expressions/expression/expression.h"
#include "expressions/implication/implication.h"
#include "expressions/expression_cast/expression_cast.h"
#include "expressions/expression_factory/expression_factory.h"

class Deduction {
    std::shared_ptr<Expression> target;

    std::vector<std::shared_ptr<Expression>> assumptions;
    std::vector<std::shared_ptr<Expression>> statements;
public:
    explicit Deduction(const std::shared_ptr<Expression> &target);


};


#endif //DEDUCTION_H
