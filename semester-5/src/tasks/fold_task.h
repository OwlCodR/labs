#ifndef FOLD_TASK_H
#define FOLD_TASK_H

#include <vector>
#include <functional>
#include <thread>
#include "base_task.h"
#include "../utils/function_types.h"
#include "../expression/expression.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("FOLD_TASK\t\t")

template<class T>
class FoldTask : public BaseTask<T> {
private:
    FoldFunctionType foldFunction;
    T initValue;
public:
    FoldTask(T initValue, FoldFunctionType foldFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
FoldTask<T>::FoldTask(T initValue, FoldFunctionType foldFunction) {
    this->initValue = initValue;
    this->foldFunction = foldFunction;
}

template<class T>
vector<T> FoldTask<T>::Eval(vector<T> args) {
    Debug(TAG, "Start .Fold()" + argsToString<T>(args));
    T value = this->initValue;
    for (int i = 0; i < args.size(); i++) {
        value = this->foldFunction(value, args[i]);
    }
    Debug(TAG, "Finish .Fold()" + argsToString<T>({ value }));
    return { value };
}

template<class T>
vector<T> FoldTask<T>::EvalAsync(vector<T> args) {
    return this->Eval(args);
}

#endif