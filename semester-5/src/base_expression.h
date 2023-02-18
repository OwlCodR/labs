#ifndef BASE_EXPRESSION_H
#define BASE_EXPRESSION_H

#include <vector>
#include "statement/base_statement.h"

using namespace std;

template<class T>
class BaseExpression {
public:
    vector<T> values;
    vector<BaseStatement<T>*> actions;
};

#endif