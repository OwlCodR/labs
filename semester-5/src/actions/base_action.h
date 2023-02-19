#ifndef BASE_ACTION_H
#define BASE_ACTION_H

#include <vector>
#include <functional>

using namespace std;

template<class T>
class BaseAction {
public:
    virtual vector<T> Eval(vector<T> args) = 0;
};

#endif