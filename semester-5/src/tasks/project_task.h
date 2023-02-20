#ifndef PROJECT_TASK_H
#define PROJECT_TASK_H

#include <vector>
#include <functional>
#include "base_task.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG "PROJECT_TASK\t"

template<class T>
class ProjectTask : public BaseTask<T> {
private:
    vector<ProjectFunctionType> projectFunctions;
public:
    ProjectTask(vector<ProjectFunctionType> projectFunctions);
    vector<T> Eval(vector<T> args);
};

template<class T>
ProjectTask<T>::ProjectTask(vector<ProjectFunctionType> projectFunctions) {
    this->projectFunctions = projectFunctions;
}

template<class T>
vector<T> ProjectTask<T>::Eval(vector<T> args) {
    // TODO Check count of functions

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

#endif