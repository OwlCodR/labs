#ifndef VALUE_TASK_H
#define VALUE_TASK_H

#include <vector>
#include <functional>
#include "base_task.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG string("VALUE_TASK\t\t")

template<class T>
class ValueTask : public BaseTask<T> {
private: 
    vector<T> values;
public:
    ValueTask(vector<T> values);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
ValueTask<T>::ValueTask(vector<T> values) {
    this->values = values;
}

template<class T>
vector<T> ValueTask<T>::Eval(vector<T> args) {
    Debug(TAG, ".Value()" + argsToString<T>(values));
    return values;
}

template<class T>
vector<T> ValueTask<T>::EvalAsync(vector<T> args) {
    return Eval(args);
}

#endif