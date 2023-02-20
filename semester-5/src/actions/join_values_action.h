#ifndef JOIN_VALUES_ACTION_H
#define JOIN_VALUES_ACTION_H

#include <vector>
#include <functional>
#include "base_action.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG "JOIN_VALUES_ACTION\t"

template<class T>
class JoinValuesAction : public BaseAction<T> {
private:
    vector<T> values;
public:
    JoinValuesAction(vector<T> values);
    vector<T> Eval(vector<T> args);
};

template<class T>
JoinValuesAction<T>::JoinValuesAction(vector<T> values) {
    this->values = values;
}

template<class T>
vector<T> JoinValuesAction<T>::Eval(vector<T> args) {
    Debug(TAG, "Start JoinValues" + argsToString(this->values) + argsToString(args));
    this->values.insert(this->values.end(), args.begin(), args.end());
    Debug(TAG, "Finish JoinValues" + argsToString(this->values));
    return this->values;
}

#endif