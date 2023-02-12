#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>

#include "../base_expression/base_expression.h"
#include "../statement/base_statement.h"
#include "../statement/if_statement.h"

using namespace std;

template<class T>
class Expression : public BaseExpression<T> {
public:
    Expression();
    Expression(vector<BaseStatement<T>*> actions);
    Expression value(vector<T> values);
    IfStatement<T> If(IfFunctionType ifFunction);
};

#endif