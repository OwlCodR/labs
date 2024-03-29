#ifndef JOIN_VALUES_TASK_H
#define JOIN_VALUES_TASK_H

#include <vector>
#include <functional>
#include "base_task.h"
#include "../utils/function_types.h"
#include "../expression/expression.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("JOIN_VALUES_TASK\t")

template<class T>
class JoinValuesTask : public BaseTask<T> {
private:
    vector<T> values;
public:
    JoinValuesTask(vector<T> values);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
JoinValuesTask<T>::JoinValuesTask(vector<T> values) {
    this->values = values;
}

template<class T>
vector<T> JoinValuesTask<T>::Eval(vector<T> args) {
    Debug(TAG, "Start JoinValues" + argsToString(args) + argsToString(this->values));
    args.insert(args.end(), this->values.begin(), this->values.end());
    Debug(TAG, "Finish JoinValues" + argsToString(args));
    return args;
}


template<class T>
vector<T> JoinValuesTask<T>::EvalAsync(vector<T> args) {
    return Eval(args);
}

#endif