#ifndef EVERY_ACTION_H
#define EVERY_ACTION_H

#include <vector>
#include <functional>
#include "base_action.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG "EVERY_ACTION\t\t"

template<class T>
class EveryAction : public BaseAction<T> {
private:
    vector<EveryFunctionType> everyFunctions;
public:
    EveryAction(vector<EveryFunctionType> everyFunctions);
    vector<T> Eval(vector<T> args);
};

template<class T>
EveryAction<T>::EveryAction(vector<EveryFunctionType> everyFunctions) {
    this->everyFunctions = everyFunctions;
}

template<class T>
vector<T> EveryAction<T>::Eval(vector<T> args) {
    Debug(TAG, "Start .Every()" + argsToString<T>(args));
    vector<T> newArgs;
    for (int i = 0; i < this->everyFunctions.size(); i++) {
        newArgs.push_back(everyFunctions[i](args));
    }
    Debug(TAG, "Finish .Every()" + argsToString<T>(newArgs));
    return newArgs;
}

#endif