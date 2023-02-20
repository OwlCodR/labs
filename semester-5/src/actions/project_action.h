#ifndef PROJECT_ACTION_H
#define PROJECT_ACTION_H

#include <vector>
#include <functional>
#include "base_action.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG "PROJECT_ACTION\t"

template<class T>
class ProjectAction : public BaseAction<T> {
private:
    vector<ProjectFunctionType> projectFunctions;
public:
    ProjectAction(vector<ProjectFunctionType> projectFunctions);
    vector<T> Eval(vector<T> args);
};

template<class T>
ProjectAction<T>::ProjectAction(vector<ProjectFunctionType> projectFunctions) {
    this->projectFunctions = projectFunctions;
}

template<class T>
vector<T> ProjectAction<T>::Eval(vector<T> args) {
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