#ifndef BASE_TASK_H
#define BASE_TASK_H

#include <vector>
#include <functional>

using namespace std;

template<class T>
class BaseTask {
public:
    virtual vector<T> Eval(vector<T> args) = 0;
    virtual vector<T> EvalAsync(vector<T> args) = 0;
};

#endif