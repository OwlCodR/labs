#ifndef EVERY_TASK_H
#define EVERY_TASK_H

#include <vector>
#include <functional>
#include "base_task.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG "EVERY_TASK\t\t"

template<class T>
class EveryTask : public BaseTask<T> {
private:
    vector<EveryFunctionType> everyFunctions;
public:
    EveryTask(vector<EveryFunctionType> everyFunctions);
    vector<T> Eval(vector<T> args);
};

template<class T>
EveryTask<T>::EveryTask(vector<EveryFunctionType> everyFunctions) {
    this->everyFunctions = everyFunctions;
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

#endif