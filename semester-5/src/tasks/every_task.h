#ifndef EVERY_TASK_H
#define EVERY_TASK_H

#include <thread>
#include <vector>
#include <functional>
#include "base_task.h"
#include "../utils/function_types.h"
#include "../expression/expression.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("EVERY_TASK\t\t")

template<class T>
class EveryTask : public BaseTask<T> {
private:
    void callEveryFunction(int everyFunctionIndex, vector<T> args, T& arg);
    vector<EveryFunctionType> everyFunctions;
public:
    EveryTask(vector<EveryFunctionType> everyFunctions);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
EveryTask<T>::EveryTask(vector<EveryFunctionType> everyFunctions) {
    this->everyFunctions = everyFunctions;
}

template<class T>
void EveryTask<T>::callEveryFunction(int i, vector<T> args, T& arg) {
    arg = everyFunctions[i](args);
}

template<class T>
vector<T> EveryTask<T>::Eval(vector<T> args) {
    Debug(TAG, "Start .Every()" + argsToString<T>(args));
    vector<T> newArgs;
    for (int i = 0; i < this->everyFunctions.size(); i++) {
        newArgs.push_back(everyFunctions[i](args));
    }
    Debug(TAG, "Finish .Every()" + argsToString<T>(newArgs));
    return newArgs;
}

template<class T>
vector<T> EveryTask<T>::EvalAsync(vector<T> args) {
    Debug(TAG, "Start Async .Every()" + argsToString<T>(args));

    int functionsCount = this->everyFunctions.size();

    vector<T> newArgs(functionsCount);
    vector<thread> threads;

    for (int i = 0; i < functionsCount; i++) {
        threads.push_back(
            thread(callEveryFunction, this, i, args, ref(newArgs[i]))
        );
    }

    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }

    Debug(TAG, "Finish Async .Every()" + argsToString<T>(newArgs));

    return newArgs;
}

#endif