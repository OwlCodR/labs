#ifndef IF_THEN_ELSE_TASK_H
#define IF_THEN_ELSE_TASK_H

#include <vector>
#include <functional>
#include <thread>
#include "base_task.h"
#include "../utils/function_types.h"
#include "../expression/expression.h"
#include "../statements/then_statement.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("IF_THEN_ELSE_TASK\t")

template<class T>
class IfThenElseTask : public BaseTask<T> {    
private:
    void callIfFunction(vector<T> args, bool& result);
    void callThenFunction(vector<T>& args);
    void callElseFunction(vector<T>& args);
public:
    IfFunctionType ifFunction;
    ResultFunctionType thenFunction;
    ResultFunctionType elseFunction;

    IfThenElseTask(IfFunctionType ifFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
void IfThenElseTask<T>::callThenFunction(vector<T>& args) {
    args = thenFunction(args);
}

template<class T>
void IfThenElseTask<T>::callElseFunction(vector<T>& args) {
    args = elseFunction(args);
}

template<class T>
void IfThenElseTask<T>::callIfFunction(vector<T> args, bool& result) {
    result = ifFunction(args);
}

template<class T>
IfThenElseTask<T>::IfThenElseTask(IfFunctionType ifFunction) {
    this->ifFunction = ifFunction;
}

template<class T>
vector<T> IfThenElseTask<T>::Eval(vector<T> args) {
    Debug(TAG, ".If()" + argsToString(args));
    bool ifFunctionResult = ifFunction(args);
    vector<T> result;

    if (ifFunctionResult) {
        result = thenFunction(args);
        Debug(TAG, ".Then()" + argsToString(result));
    } else {
        result = elseFunction(args);
        Debug(TAG, ".Else()" + argsToString(result));
    }
    return result;
}


template<class T>
vector<T> IfThenElseTask<T>::EvalAsync(vector<T> args) {
    Debug(TAG, ".If() Async" + argsToString(args));

    bool ifFunctionResult;
    thread ifThread(callIfFunction, this, args, ref(ifFunctionResult));
    ifThread.join();

    if (ifFunctionResult) {
        thread thenThread(callThenFunction, this, ref(args));
        thenThread.join();
        Debug(TAG, ".Then() Async" + argsToString(args));
    } else {
        thread elseThread(callElseFunction, this, ref(args));
        elseThread.join();
        Debug(TAG, ".Else() Async" + argsToString(args));
    }
    return args;
}

#endif