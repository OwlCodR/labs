#ifndef IF_THEN_ELSE_ACTION_H
#define IF_THEN_ELSE_ACTION_H

#include <vector>
#include <functional>
#include "base_action.h"

using namespace std;

template<typename T>
class IfThenElseAction : public BaseAction<T> {    
public:
    function<bool(vector<T>)> ifFunction;
    function<vector<T>(vector<T>)> thenFunction;
    function<vector<T>(vector<T>)> elseFunction;

    IfThenElseAction<T>(function<bool(vector<T>)> ifFunction);
    vector<T> Eval(vector<T> args) override;
};

template<typename T>
IfThenElseAction<T>::IfThenElseAction(function<bool(vector<T>)> ifFunction) {
    this->ifFunction = ifFunction;
}

template<typename T>
vector<T> IfThenElseAction<T>::Eval(vector<T> args) {
    if (ifFunction(args)) {
        return thenFunction(args);
    } else {
        return elseFunction(args);
    }
};

#endif