#ifndef ALL_TASK_H
#define ALL_TASK_H

#include <vector>
#include <functional>
#include "base_task.h"
#include "../utils/function_types.h"
#include "../expression/expression.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("ALL_TASK\t\t")

template<class T>
class AllTask : public BaseTask<T> {
private:
    FilterFunctionType allFunction;
public:
    AllTask(FilterFunctionType allFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
AllTask<T>::AllTask(FilterFunctionType allFunction) {
    this->allFunction = allFunction;
}

template<class T>
vector<T> AllTask<T>::Eval(vector<T> args) {
    Debug(TAG, "Start .All()" + argsToString<T>(args));
    vector<T> newArgs;
    for (int i = 0; i < args.size(); i++) {
        if (allFunction(args[i])) {
            newArgs.push_back(args[i]);
        }
    }
    Debug(TAG, "Finish .All()" + argsToString<T>(newArgs));
    return newArgs;
}

template<class T>
vector<T> AllTask<T>::EvalAsync(vector<T> args) {
    // TODO Implement async evaluation
    return Eval(args);
}

#endif