#ifndef BASE_STATEMENT_H
#define BASE_STATEMENT_H

using namespace std;

template<class T>
class BaseStatement {
public:
    virtual ~BaseStatement() {};
    virtual T Eval();
};

#endif