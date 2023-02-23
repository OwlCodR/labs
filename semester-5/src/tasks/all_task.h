#ifndef ALL_TASK_H
#define ALL_TASK_H

#include <vector>
#include <functional>
#include <mutex>
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
    void callAllFunction(T arg, vector<T>& newArgs);
public:
    AllTask(FilterFunctionType allFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
void AllTask<T>::callAllFunction(T arg, vector<T>& newArgs) {
    mutex m;
    if (allFunction(arg)) {
        m.lock();
        newArgs.push_back(arg);
        m.unlock();
    }
}

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
    Debug(TAG, "Start Async .All()" + argsToString<T>(args));

    vector<thread> threads;
    vector<T> newArgs;

    for (int i = 0; i < args.size(); i++) {
        threads.push_back(
            thread(callAllFunction, this, args[i], ref(newArgs))
        );
    }

    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }

    Debug(TAG, "Finish Async .All()" + argsToString<T>(newArgs));
    return newArgs;
}

#endif