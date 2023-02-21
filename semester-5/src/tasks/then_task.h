#ifndef THEN_TASK_H
#define THEN_TASK_H

#include <vector>
#include <functional>
#include "base_task.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG string("THEN_TASK\t\t")

template<class T>
class ThenTask : public BaseTask<T> {
private:
    ResultFunctionType thenFunction;
public:
    ThenTask(ResultFunctionType thenFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
ThenTask<T>::ThenTask(ResultFunctionType thenFunction) {
    this->thenFunction = thenFunction;
}

template<class T>
vector<T> ThenTask<T>::Eval(vector<T> args) {
    Debug(TAG, "Start .Then()" + argsToString<T>(args));
    args = this->thenFunction(args);
    Debug(TAG, "Finish .Then()" + argsToString<T>(args));
    return args;
}

template<class T>
vector<T> ThenTask<T>::EvalAsync(vector<T> args) {
    // TODO Implement async evaluation
    return Eval(args);
}

#endif