#ifndef MAP_TASK_H
#define MAP_TASK_H

#include <vector>
#include <functional>
#include <thread>
#include "base_task.h"
#include "../utils/function_types.h"
#include "../expression/expression.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("MAP_TASK\t\t")

template<class T>
class MapTask : public BaseTask<T> {
private:
    MapFunctionType mapFunction;
    void callMapFunction(T& arg);
public:
    MapTask(MapFunctionType mapFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
void MapTask<T>::callMapFunction(T& arg) {
    arg = this->mapFunction(arg);
}

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
    Debug(TAG, "Start Async .Map()" + argsToString<T>(args));

    vector<thread> threads;
    for (int i = 0; i < args.size(); i++) { 
        threads.push_back(
            thread(callMapFunction, this, ref(args[i]))
        );
    }

    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }

    Debug(TAG, "Finish Async .Map()" + argsToString<T>(args));
    return args;
}

#endif