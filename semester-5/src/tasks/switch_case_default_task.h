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
    void callSwitchFunction(vector<T> args, T& arg);
    void callCaseFunction(vector<T>& args, T value);
    void callDefaultFunction(vector<T>& args, T value);
public:
    map<T, ResultFunctionType> cases;
    ResultFunctionType defaultFunction;

    SwitchCaseDefaultTask(SwitchFunctionType switchFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
void SwitchCaseDefaultTask<T>::callDefaultFunction(vector<T>& args, T value) {
    args = defaultFunction(args);
}

template<class T>
void SwitchCaseDefaultTask<T>::callSwitchFunction(vector<T> args, T& arg) {
    arg = switchFunction(args);
}

template<class T>
void SwitchCaseDefaultTask<T>::callCaseFunction(vector<T>& args, T value) {
    args = cases[value](args);
}

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
    T value;

    thread switchThread(callSwitchFunction, this, args, ref(value));
    switchThread.join();

    Debug(TAG, "Start .Switch() " + to_string(value));

    if (cases.find(value) != cases.end()) {
        thread caseThread(callCaseFunction, this, ref(args), value);
        caseThread.join();

        Debug(TAG, "Finish .Case() " + argsToString(args));
        return args;
    }

    thread defaultThread(callDefaultFunction, this, ref(args), value);
    defaultThread.join();

    Debug(TAG, "Finish .Default()" + argsToString(args));
    return args;
}

#endif