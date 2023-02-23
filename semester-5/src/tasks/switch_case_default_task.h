#ifndef SWITCH_CASE_DEFAULT_TASK_H
#define SWITCH_CASE_DEFAULT_TASK_H

#include <vector>
#include <functional>
#include <map>
#include "base_task.h"
#include "../utils/function_types.h"
#include "../expression/expression.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("SWITCH_CASE_DEFAULT\t")

template<class T>
class SwitchCaseDefaultTask : public BaseTask<T> {
private:
    SwitchFunctionType switchFunction;
public:
    map<T, ResultFunctionType> cases;
    ResultFunctionType defaultFunction;

    SwitchCaseDefaultTask(SwitchFunctionType switchFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
SwitchCaseDefaultTask<T>::SwitchCaseDefaultTask(SwitchFunctionType switchFunction) {
    this->switchFunction = switchFunction;
}

template<class T>
vector<T> SwitchCaseDefaultTask<T>::Eval(vector<T> args) {
    T value = switchFunction(args);
    Debug(TAG, "Start .Switch() " + to_string(value));

    if (cases.find(value) != cases.end()) {
        vector<T> newArgs = cases[value](args);
        Debug(TAG, "Finish .Case() " + argsToString(newArgs));
        return newArgs;
    }

    vector<T> newArgs = defaultFunction(args);
    Debug(TAG, "Finish .Default()" + argsToString(newArgs));
    return newArgs;
}


template<class T>
vector<T> SwitchCaseDefaultTask<T>::EvalAsync(vector<T> args) {
    // TODO Implement async evaluation
    return Eval(args);
}

#endif