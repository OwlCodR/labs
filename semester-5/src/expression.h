#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>

#include "base_expression.h"
#include "statement/base_statement.h"
#include "statement/if_statement.h"
#include "function_types.h"
#include "actions/map_action.h"
#include "actions/then_action.h"
#include "actions/every_action.h"
#include "log.h"


using namespace std;

#define TAG "EXPRESSION\t\t"

template<class T>
class Expression : public BaseExpression<T> {
private:
    void checkValuesOverwrite();
public:
    Expression();
    Expression(vector<BaseStatement<T>*> actions);
    Expression value(vector<T> values);
    IfStatement<T> If(IfFunctionType ifFunction);
    Expression<T> Map(MapFunctionType mapFunction);
    Expression<T> Then(ResultFunctionType thenFunction);
    Expression<T> Every(vector<EveryFunctionType> everyFunctions);
    vector<T> Eval();
    vector<T> Eval(vector<T> values);
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
Expression<T>::Expression(vector<BaseStatement<T>*> actions) {
    this->actions = actions;
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
    this->actions.push_back(new MapAction<T>(mapFunction));
    return *this;
}

template<class T>
Expression<T> Expression<T>::Then(ResultFunctionType thenFunction) {
    this->actions.push_back(new ThenAction<T>(thenFunction));
    return *this;
}


template<class T>
Expression<T> Expression<T>::Every(vector<EveryFunctionType> everyFunctions) {
    this->actions.push_back(new EveryAction<T>(everyFunctions));
    return *this;
}

template<class T>
vector<T> Expression<T>::Eval() {
    Debug(TAG, "Start Expression" + argsToString(this->values));
    for (int i = 0 ; i < this->actions.size(); i++) {
        this->values = this->actions[i]->Eval(this->values);
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


#endif