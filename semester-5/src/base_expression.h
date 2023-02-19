#ifndef BASE_EXPRESSION_H
#define BASE_EXPRESSION_H

#include <vector>
#include "actions/base_action.h"

using namespace std;

template<class T>
class BaseExpression {
public:
    vector<T> values;
    vector<BaseAction<T>*> actions;
};

#endif