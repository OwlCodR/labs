#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>

#include "base_expression.h"
#include "../statements/base_statement.h"
#include "../statements/if_statement.h"
#include "../statements/switch_statement.h"
#include "../utils/function_types.h"
#include "../tasks/map_task.h"
#include "../tasks/then_task.h"
#include "../tasks/every_task.h"
#include "../tasks/project_task.h"
#include "../tasks/join_values_task.h"
#include "../tasks/value_task.h"
#include "../tasks/switch_case_default_task.h"
#include "../tasks/all_task.h"
#include "../tasks/any_task.h"
#include "../tasks/fold_task.h"
#include "../utils/log.h"

using namespace std;

#define TAG string("EXPRESSION\t\t")

/**
 * @brief Class that constructs mathematical expressions.
 * After calling a function it adds a task to list and evaluates values 
 * only after calling Expression::Eval() or Expression::EvalAsync()
 * 
 * @tparam T Value type. Can be int, double, float or custom type with overridden basic operators
 */
template<class T>
class Expression : public BaseExpression<T> {
private:
    void checkValuesOverwrite();
    void checkEmptyValues();
    void checkEmptyActions();
public:
    Expression();
    Expression(vector<T> values);
    Expression(vector<BaseStatement<T>*> tasks);
    Expression Value(vector<T> values);
    IfStatement<T> If(IfFunctionType ifFunction);
    SwitchStatement<T> Switch(SwitchFunctionType switchFunction);
    Expression<T> Map(MapFunctionType mapFunction);
    Expression<T> Then(ResultFunctionType thenFunction);
    Expression<T> Every(vector<EveryFunctionType> everyFunctions);
    Expression<T> Project(vector<ProjectFunctionType> projectFunctions);
    Expression<T> JoinValues(vector<T> values);
    Expression<T> All(FilterFunctionType allFunction);
    Expression<T> Any(FilterFunctionType anyFunction);
    Expression<T> Fold(T initValue, FoldFunctionType anyFunction);
    vector<T> Eval();
    vector<T> Eval(vector<T> values);
    vector<T> EvalAsync();
    vector<T> EvalAsync(vector<T> values);
};

template<class T>
void Expression<T>::checkValuesOverwrite() {
    if (!this->values.empty()) {
        Warning(TAG, "You have already passed values! They have been overwritten!");
    }
}

template<class T>
void Expression<T>::checkEmptyValues() {
    if (this->values.empty()) {
        Warning(TAG, "Values are empty!");
    }
}

template<class T>
void Expression<T>::checkEmptyActions() {
    if (this->tasks.empty()) {
        string error = "No operations in expression!";
        Error(TAG, error);
        throw invalid_argument(error);
    }
}

template<class T>
Expression<T>::Expression() {}

template<class T>
Expression<T>::Expression(vector<T> values) {
    this->values = values;
}

template<class T>
Expression<T>::Expression(vector<BaseStatement<T>*> tasks) {
    this->tasks = tasks;
}

/**
 * @brief Modifies values by setting new values.
 *
 * @tparam T Value type.
 * @param values New values to apply.
 * @return Expression<T> Expression with new task to modify values.
 *
 * @code {.c++}
 * Expression<int> exp = Expression<int>({ -10, 1, 10 })
 * .Map([](int arg) -> int { return arg + 1 })
 * .Value({ 5, 4 })
 * exp.Eval(); // { 5, 4 }
 * @endcode
 */
template<class T>
Expression<T> Expression<T>::Value(vector<T> values) {
    this->tasks.push_back(new ValueTask<T>(values));
    return *this;
}

/**
 * @brief Entry point of If-Then-Else construction.
 *
 * @tparam T Value type.
 * @param ifFunction Takes list of values, if returns true Then() will be called, Else() otherwise.
 * @return IfStatement<T> Statement which lets to call .Then() method.
 *
 * @code {.c++}
 * Expression<int> exp = Expression<int>({ -10, 10 })
 * .If([](vector<int> args) -> bool { return args[0] == args[1]; })
 * .Then([](vector<int> args) -> vector<int> { return args; })
 * .Else([](vector<int> args) -> vector<int> { args[0] = args[1]; return args; })
 * exp.Eval(); // { 10, 10 }
 * @endcode
 */
template<class T>
IfStatement<T> Expression<T>::If(IfFunctionType ifFunction) {
    return IfStatement<T>(this, ifFunction);
}

/**
 * @brief Entry point of Switch-Case-Default construction.
 * 
 * @tparam T Value type.
 * @param switchFunction Takes list of values, returns single value to compare cases with.
 * @return SwitchStatement<T>  Statement which lets to call .Case() and .Default() methods.
 */
template<class T>
SwitchStatement<T> Expression<T>::Switch(SwitchFunctionType switchFunction) {
    return SwitchStatement<T>(this, switchFunction);
}

/**
 * @brief Modifies values by filtering every value with condition.
 * Sets values with filtered values.
 * 
 * @tparam T Value type.
 * @param allFunction Takes single value, returns false if value should be removed.
 * @return Expression<T> Expression with new task to modify values.
 * 
 * @code {.c++}
 * Expression<int> exp = Expression<int>({ -10, 1, 10 })
 * .All([](int arg) -> int { return arg > 0; })
 * exp.Eval(); // { 1, 10 }
 * @endcode
 */
template<class T>
Expression<T> Expression<T>::All(FilterFunctionType allFunction) {
    this->tasks.push_back(new AllTask<T>(allFunction));
    return *this;
}

/**
 * @brief Modifies values by filtering every value with condition.
 * Sets values with the first filtered value.
 * 
 * @tparam T Value type.
 * @param anyFunction Takes single value, returns false if value should be removed.
 * @return Expression<T> Expression with new task to modify values.
 */
template<class T>
Expression<T> Expression<T>::Any(FilterFunctionType anyFunction) {
    this->tasks.push_back(new AnyTask<T>(anyFunction));
    return *this;
}

/**
 * @brief Modifies values by applying the function to every value.
 *
 * @tparam T Value type.
 * @param mapFunction Takes single value, returns single value.
 * @return Expression<T> Expression with new task to modify values.
 *
 * @code {.c++}
 * Expression<int> exp = Expression<int>({ -10, 1, 10 })
 * .Map([](int arg) -> int { return arg + 1 })
 * exp.Eval(); // { -9, 2, 11 }
 * @endcode
 */
template<class T>
Expression<T> Expression<T>::Map(MapFunctionType mapFunction) {
    this->tasks.push_back(new MapTask<T>(mapFunction));
    return *this;
}

/**
 * @brief Modifies values by applying the function to all values.
 * 
 * @tparam T Value type.
 * @param thenFunction Takes list of values, returns list of values.
 * @return Expression<T> Expression with new task to modify values.
 * 
 * @code {.c++}
 * Expression<int> exp = Expression<int>({ -10, 1, 10 })
 * .Then(
 *     [](vector<int> args) -> vector<int> { 
 *         args[0] = args[0] + 1; 
 *         return args; 
 *     }
 * )
 * exp.Eval(); // { -9, 1, 10 }
 * @endcode
 */
template<class T>
Expression<T> Expression<T>::Then(ResultFunctionType thenFunction) {
    this->tasks.push_back(new ThenTask<T>(thenFunction));
    return *this;
}

/**
 * @brief Modifies values by setting new value per function.
 * 
 * @tparam T Value type.
 * @param everyFunctions Takes list of values, returns single value.
 * @return Expression<T> Expression with new task to modify values.
 * 
 * @code {.c++}
 * Expression<int> exp = Expression<int>({ -10, 1, 10 })
 * .Every({
 *     [](vector<int> args) -> int { return args[0] + 100; },
 *     [](vector<int> args) -> int { return args[2]; },
 * })
 * exp.Eval(); // { 90, 10 }
 * @endcode
 */
template<class T>
Expression<T> Expression<T>::Every(vector<EveryFunctionType> everyFunctions) {
    this->tasks.push_back(new EveryTask<T>(everyFunctions));
    return *this;
}

/**
 * @brief Modifies values by removing values where NULL returns from function.
 *
 * @tparam T Value type.
 * @param projectFunctions Takes single value, returns single value. Count of functions should be equal to count of values.
 * @return Expression<T> Expression with new task to modify values.
 * 
 * @code {.c++}
 * Expression<int> exp = Expression<int>({ -10, 1, 10 })
 * .Project({
 *     [](int arg1) -> int { return NULL; },
 *     [](int arg2) -> int { return arg2; },
 *     [](int arg3) -> int { return NULL; },
 * })
 * exp.Eval(); // { 1 }
 * @endcode
 */
template<class T>
Expression<T> Expression<T>::Project(vector<ProjectFunctionType> projectFunctions) {
    this->tasks.push_back(new ProjectTask<T>(projectFunctions));
    return *this;
}

/**
 * @brief Modifies values by adding values to the end of the list of expression values.
 * 
 * @tparam T Value type.
 * @param values List of values to add.
 * @return Expression<T> Expression with new task to modify values.
 * 
 * @code {.c++}
 * Expression<int> exp = Expression<int>({ -10, 1, 10 })
 * .JoinValues({ 5, 0, 5 })
 * exp.Eval(); // { -10, 1, 10, 5, 0, 5 }
 * @endcode
 */
template<class T>
Expression<T> Expression<T>::JoinValues(vector<T> values) {
    this->tasks.push_back(new JoinValuesTask<T>(values));
    return *this;
}

template<class T>
Expression<T> Expression<T>::Fold(T initValue, FoldFunctionType foldFunction) {
    this->tasks.push_back(new FoldTask<T>(initValue, foldFunction));
    return *this;
}

template<class T>
vector<T> Expression<T>::Eval() {
    checkEmptyValues();
    checkEmptyActions();

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
    checkEmptyValues();
    checkEmptyActions();

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