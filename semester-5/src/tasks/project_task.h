#ifndef PROJECT_TASK_H
#define PROJECT_TASK_H

#include <vector>
#include <functional>
#include <thread>
#include "base_task.h"
#include "../utils/function_types.h"
#include "../expression/expression.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("PROJECT_TASK\t\t")

template<class T>
class ProjectTask : public BaseTask<T> {
private:
    void checkFunctionsCount(vector<T> args);
    void callProjectFunction(int i, T& arg);
    vector<ProjectFunctionType> projectFunctions;
public:
    ProjectTask(vector<ProjectFunctionType> projectFunctions);
    vector<T> Eval(vector<T> args);
    vector<T> EvalAsync(vector<T> args);
};

template<class T>
void ProjectTask<T>::checkFunctionsCount(vector<T> args) {
    int functionsCount = this->projectFunctions.size();
    int argsCount = args.size();
    if (functionsCount != argsCount) {
        string error = "Project functions count is not equal to count of arguments";
        Debug(
            TAG, 
            "Project functions count is " + to_string(functionsCount) +
            " whereas args count is " + to_string(argsCount)
        );
        throw length_error(error);
    }
}

template<class T>
void ProjectTask<T>::callProjectFunction(int i, T& arg) {
    arg = this->projectFunctions[i](arg);
}

template<class T>
ProjectTask<T>::ProjectTask(vector<ProjectFunctionType> projectFunctions) {
    this->projectFunctions = projectFunctions;
}

template<class T>
vector<T> ProjectTask<T>::Eval(vector<T> args) {
    checkFunctionsCount(args);
    
    Debug(TAG, "Start .Project()" + argsToString<T>(args));
    vector<T> newArgs;
    for (int i = 0; i < this->projectFunctions.size(); i++) {
        T arg = this->projectFunctions[i](args[i]);
        if (arg != NULL) {
            newArgs.push_back(arg);
        }
    }
    Debug(TAG, "Finish .Project()" + argsToString<T>(newArgs));
    return args;
}

template<class T>
vector<T> ProjectTask<T>::EvalAsync(vector<T> args) {
    checkFunctionsCount(args);

    Debug(TAG, "Start Async .Project()" + argsToString<T>(args));

    vector<T> newArgs;
    vector<thread> threads;

    for (int i = 0; i < this->projectFunctions.size(); i++) {
        threads.push_back(
            thread(callProjectFunction, this, i, ref(args[i]))
        );
    }

    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
        if (args[i] != NULL) {
            newArgs.push_back(args[i]);
        }
    }
    Debug(TAG, "Finish Async .Project()" + argsToString<T>(newArgs));
    return newArgs;
}

#endif