#ifndef MAP_ACTION_H
#define MAP_ACTION_H

#include <vector>
#include <functional>
#include "base_action.h"

using namespace std;

template<typename T>
class MapAction : public BaseAction<T> {
private:
    function<T(T)> mapFunction;
public:
    MapAction<T>(function<T(T)> mapFunction);
    vector<T> Eval(vector<T> args) override;
};

template<typename T>
MapAction<T>::MapAction(function<T(T)> mapFunction) {
    this->mapFunction = mapFunction;
}

template<typename T>
vector<T> MapAction<T>::Eval(vector<T> args) {
    for (int i = 0; i < args.size(); i++) {
        args[i] = mapFunction(args[i]);
    }
    return args;
};

#endif