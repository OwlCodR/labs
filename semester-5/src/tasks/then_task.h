#ifndef THEN_TASK_H
#define THEN_TASK_H

#include <vector>
#include <functional>
#include <thread>
#include "base_task.h"
#include "../utils/function_types.h"
#include "../expression/expression.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("THEN_TASK\t\t")

template<class T>
class ThenTask : public BaseTask<T> {
private:
    ResultFunctionType thenFunction;
    void callThenFunction(vector<T>& args);
public:
    ThenTask(ResultFunctionType thenFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
void ThenTask<T>::callThenFunction(vector<T>& args) {
    args = this->thenFunction(args);
}

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
    Debug(TAG, "Start Async .Then()" + argsToString<T>(args));

    thread t(callThenFunction, this, ref(args));
    t.join();

    Debug(TAG, "Finish Async .Then()" + argsToString<T>(args));
    return args;
}

#endif