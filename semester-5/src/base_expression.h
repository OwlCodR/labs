#ifndef BASE_EXPRESSION_H
#define BASE_EXPRESSION_H

#include <vector>
#include "tasks/base_task.h"

using namespace std;

template<class T>
class BaseExpression {
public:
    vector<T> values;
    vector<BaseTask<T>*> tasks;
};

#endif