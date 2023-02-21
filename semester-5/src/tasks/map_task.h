#ifndef MAP_TASK_H
#define MAP_TASK_H

#include <vector>
#include <functional>
#include "base_task.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG string("MAP_TASK\t\t")

template<class T>
class MapTask : public BaseTask<T> {
private:
    MapFunctionType mapFunction;
public:
    MapTask(MapFunctionType mapFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
MapTask<T>::MapTask(MapFunctionType mapFunction) {
    this->mapFunction = mapFunction;
}

template<class T>
vector<T> MapTask<T>::Eval(vector<T> args) {
    Debug(TAG, "Start .Map()" + argsToString<T>(args));
    for (int i = 0; i < args.size(); i++) {
        args[i] = this->mapFunction(args[i]);
    }
    Debug(TAG, "Finish .Map()" + argsToString<T>(args));
    return args;
}

template<class T>
vector<T> MapTask<T>::EvalAsync(vector<T> args) {
    // TODO Implement async evaluation
    return Eval(args);
}

#endif