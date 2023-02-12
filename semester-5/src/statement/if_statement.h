#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include <functional>
#include <vector>
#include "base_statement.h"

template<class A> // FIX ERROR USING THIS
class Expression;

using namespace std;

#define IfFunctionType function<bool(vector<T>)>
#define ResultFunctionType function<T(vector<T>)>

template<class T>
class IfStatement : public BaseStatement<T> {
private:
    Expression<T>* parent;
    IfFunctionType ifFunction;
    ResultFunctionType thenFunction;
    ResultFunctionType elseFunction;

    vector<BaseStatement<T>*> getUpdatedStatements(Expression<T>* parent);

public:
    IfStatement(Expression<T>* parent, IfFunctionType ifFunction);
    IfStatement<T> Then(ResultFunctionType function); // RETURN HERE ElseStatement
    Expression<T> Else(ResultFunctionType function);
    T Eval(vector<T> args);
};

#endif