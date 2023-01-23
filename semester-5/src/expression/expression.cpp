#include <functional>
#include <vector>
#include <stdarg.h>

#include "../base_expression/base_expression.cpp"

using namespace std;

template<class T>
class Expression : public BaseExpression<T> {
public:
    Expression value(int argsCount, ...) {
        va_list args;
        va_start(args, argsCount);
        for (int i = 0; i < argsCount; i++) {
            T arg = va_arg(args, T);
            this->values.push_back(arg);
        }
        va_end(args);
        return *this;
    }
};