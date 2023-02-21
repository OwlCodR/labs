#ifndef PROJECT_TASK_H
#define PROJECT_TASK_H

#include <vector>
#include <functional>
#include "base_task.h"
#include "../function_types.h"
#include "../expression.h"
#include "../log.h"

using namespace std;

#define TAG string("PROJECT_TASK\t\t")

template<class T>
class ProjectTask : public BaseTask<T> {
private:
    void checkFunctionsCount(vector<T> args);
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
    // TODO Implement async evaluation
    return Eval(args);
}

#endif