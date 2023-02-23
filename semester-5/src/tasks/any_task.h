#ifndef ANY_TASK_H
#define ANY_TASK_H

#include <vector>
#include <functional>
#include <thread>
#include "base_task.h"
#include "../utils/function_types.h"
#include "../expression/expression.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("ANY_TASK\t\t")

template<class T>
class AnyTask : public BaseTask<T> {
private:
    FilterFunctionType anyFunction;
    void callAnyFunction(T arg, vector<T>& newArgs);
public:
    AnyTask(FilterFunctionType anyFunction);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
void AnyTask<T>::callAnyFunction(T arg, vector<T>& newArgs) {
    mutex m;

    if (anyFunction(arg)) {
        m.lock();
        newArgs.push_back(arg);
        m.unlock();
    }
}

template<class T>
AnyTask<T>::AnyTask(FilterFunctionType anyFunction) {
    this->anyFunction = anyFunction;
}

template<class T>
vector<T> AnyTask<T>::Eval(vector<T> args) {
    Debug(TAG, "Start .Any()" + argsToString<T>(args));
    for (int i = 0; i < args.size(); i++) {
        if (anyFunction(args[i])) {
            vector<T> arg = { args[i] };
            Debug(TAG, "Finish .Any()" + argsToString<T>(arg));
            return arg;
        }
    }
    Debug(TAG, "Finish .Any()" + argsToString<T>({ }));
    return { };
}

template<class T>
vector<T> AnyTask<T>::EvalAsync(vector<T> args) {
    Debug(TAG, "Start Async .Any()" + argsToString<T>(args));
    
    vector<T> newArgs;
    vector<thread> threads;
    for (int i = 0; i < args.size(); i++) {
        threads.push_back(
            thread(callAnyFunction, this, args[i], ref(newArgs))
        );
    }

    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }

    if (!newArgs.empty()) {
        vector<T> arg = { newArgs[0] };
        Debug(TAG, "Finish Async .Any()" + argsToString<T>(arg));
        return arg;
    }

    Debug(TAG, "Finish Async .Any()" + argsToString<T>({ }));
    return { };
}

#endif