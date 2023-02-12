#include "if_statement.h"

template<class T>
IfStatement<T>::IfStatement(Expression<T>* parent, IfFunctionType ifFunction) {
    this->parent = parent;
    this->ifFunction = ifFunction;
};

template<class T>
IfStatement<T> IfStatement<T>::Then(ResultFunctionType function) {
    this->thenFunction = function;
    return IfStatement<T>(getUpdatedStatements(parent));
}

template<class T>
Expression<T> IfStatement<T>::Else(ResultFunctionType function) {
    this->elseFunction = function;
    return Expression<T>(getUpdatedStatements(parent));
}

template<class T>
T IfStatement<T>::Eval(vector<T> args) {
    if (ifFunction(args)) {
        return thenFunction(args);
    } else {
        return elseFunction(args);
    }
}

template<class T>
vector<BaseStatement<T>*> IfStatement<T>::getUpdatedStatements(Expression<T>* parent) {
    vector<BaseStatement<T>*> actions = this->parent->actions;
    actions.pop_back();
    actions.push_back(*this);
    return actions;
}
