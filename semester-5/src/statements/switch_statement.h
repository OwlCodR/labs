#ifndef SWITCH_STATEMENT_H
#define SWITCH_STATEMENT_H

#include <functional>
#include <vector>
#include "base_statement.h"
#include "../expression/expression.h"
#include "then_statement.h"
#include "../utils/function_types.h"
#include "../tasks/switch_case_default_task.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("SWITCH_STATEMENT\t\t")

template<class T>
class SwitchStatement : public BaseStatement<T> {
private:
    SwitchCaseDefaultTask<T>* task;
    SwitchStatement(Expression<T>* parent, SwitchCaseDefaultTask<T>* task);
    void checkCaseOverwrite(T value);
public:
    SwitchStatement(Expression<T>* parent, SwitchFunctionType switchFunction);
    SwitchStatement<T> Case(T value, ResultFunctionType caseFunction);
    Expression<T> Default(ResultFunctionType defaultFunction);
};

template<class T>
void SwitchStatement<T>::checkCaseOverwrite(T value) {
    if (task->cases.find(value) != task->cases.end()) {
        string error = "You have already passed the case with value " + to_string(value);
        Error(TAG, error);
        throw invalid_argument(error);
    }
};

template<class T>
SwitchStatement<T>::SwitchStatement(Expression<T>* parent, SwitchCaseDefaultTask<T>* task) {
    this->parent = parent;
    this->task = task;
};

template<class T>
SwitchStatement<T>::SwitchStatement(Expression<T>* parent, SwitchFunctionType switchFunction) {
    this->parent = parent;
    this->task = new SwitchCaseDefaultTask<T>(switchFunction);
};

template<class T>
SwitchStatement<T> SwitchStatement<T>::Case(T value, ResultFunctionType caseFunction) {
    checkCaseOverwrite(value);
    this->task->cases[value] = caseFunction;
    return SwitchStatement<T>(this->parent, this->task);
}


template<class T>
Expression<T> SwitchStatement<T>::Default(ResultFunctionType defaultFunction) {
    this->task->defaultFunction = defaultFunction;
    this->parent->tasks.push_back(this->task);
    return *(this->parent);
}

#endif