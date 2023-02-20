#ifndef MAP_ACTION_H
#define MAP_ACTION_H

#include <vector>
#include <functional>
#include "base_action.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG "MAP_ACTION\t\t"

template<class T>
class MapAction : public BaseAction<T> {
private:
    MapFunctionType mapFunction;
public:
    MapAction(MapFunctionType mapFunction);
    vector<T> Eval(vector<T> args);
};

template<class T>
MapAction<T>::MapAction(MapFunctionType mapFunction) {
    this->mapFunction = mapFunction;
}

template<class T>
vector<T> MapAction<T>::Eval(vector<T> args) {
    Debug(TAG, "Start .Map()" + argsToString<T>(args));
    for (int i = 0; i < args.size(); i++) {
        args[i] = this->mapFunction(args[i]);
    }
    Debug(TAG, "Finish .Map()" + argsToString<T>(args));
    return args;
}

#endif