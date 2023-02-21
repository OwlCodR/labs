#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>

#include "base_expression.h"
#include "statement/base_statement.h"
#include "statement/if_statement.h"
#include "function_types.h"
#include "tasks/map_task.h"
#include "tasks/then_task.h"
#include "tasks/every_task.h"
#include "tasks/project_task.h"
#include "tasks/join_values_task.h"
#include "log.h"

using namespace std;

#define TAG string("EXPRESSION\t\t")

template<class T>
class Expression : public BaseExpression<T> {
private:
    void checkValuesOverwrite();
public:
    Expression();
    Expression(vector<BaseStatement<T>*> tasks);
    Expression value(vector<T> values);
    IfStatement<T> If(IfFunctionType ifFunction);
    Expression<T> Map(MapFunctionType mapFunction);
    Expression<T> Then(ResultFunctionType thenFunction);
    Expression<T> Every(vector<EveryFunctionType> everyFunctions);
    Expression<T> Project(vector<ProjectFunctionType> projectFunctions);
    Expression<T> JoinValues(vector<T> values);
    vector<T> Eval();
    vector<T> Eval(vector<T> values);
    vector<T> EvalAsync();
    vector<T> EvalAsync(vector<T> values);
};

template<class T>
Expression<T>::Expression() {}

template<class T>
void Expression<T>::checkValuesOverwrite() {
    if (!this->values.empty()) {
        Warning(TAG, "You have already passed values! They have been overwritten!");
    }
}

template<class T>
Expression<T>::Expression(vector<BaseStatement<T>*> tasks) {
    this->tasks = tasks;
}

template<class T>
Expression<T> Expression<T>::value(vector<T> values) {
    checkValuesOverwrite();
    this->values = values;

    Debug(TAG, ".value()" + argsToString(this->values));
    return *this;
}

template<class T>
IfStatement<T> Expression<T>::If(IfFunctionType ifFunction) {
    return IfStatement<T>(this, ifFunction);
}

template<class T>
Expression<T> Expression<T>::Map(MapFunctionType mapFunction) {
    this->tasks.push_back(new MapTask<T>(mapFunction));
    return *this;
}

template<class T>
Expression<T> Expression<T>::Then(ResultFunctionType thenFunction) {
    this->tasks.push_back(new ThenTask<T>(thenFunction));
    return *this;
}


template<class T>
Expression<T> Expression<T>::Every(vector<EveryFunctionType> everyFunctions) {
    this->tasks.push_back(new EveryTask<T>(everyFunctions));
    return *this;
}

template<class T>
Expression<T> Expression<T>::Project(vector<ProjectFunctionType> projectFunctions) {
    this->tasks.push_back(new ProjectTask<T>(projectFunctions));
    return *this;
}

template<class T>
Expression<T> Expression<T>::JoinValues(vector<T> values) {
    this->tasks.push_back(new JoinValuesTask<T>(values));
    return *this;
}

template<class T>
vector<T> Expression<T>::Eval() {
    Debug(TAG, "Start Expression" + argsToString(this->values));
    for (int i = 0 ; i < this->tasks.size(); i++) {
        this->values = this->tasks[i]->Eval(this->values);
    }
    Debug(TAG, "Finish Expression" + argsToString(this->values));
    return this->values;
}

template<class T>
vector<T> Expression<T>::Eval(vector<T> values) {
    checkValuesOverwrite();
    this->values = values;
    Eval();
    return this->values;
}

template<class T>
vector<T> Expression<T>::EvalAsync() {
    Debug(TAG, "Start Expression" + argsToString(this->values));
    for (int i = 0; i < this->tasks.size(); i++) {
        this->values = this->tasks[i]->EvalAsync(this->values);
    }
    Debug(TAG, "Finish Expression" + argsToString(this->values));
    return this->values;
}

template<class T>
vector<T> Expression<T>::EvalAsync(vector<T> values) {
    checkValuesOverwrite();
    this->values = values;
    EvalAsync();
    return this->values;
}

#endif