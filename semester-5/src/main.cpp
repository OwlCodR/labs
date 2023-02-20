#include "iostream"
#include "expression.h"
#include "log.h"

using namespace std;

#define TAG "MAIN\t\t\t"

int main() {
    Expression<int> exp = Expression<int>().value({ 0, 10 })
        .If(
            [](vector<int> args) -> bool
            { 
                return args[0] > args[1];
            }
        )
        .Then(
            [](vector<int> args) -> vector<int>
            { 
                return { args[0] + args[1] };
            }
        )
        .Else(
            [](vector<int> args) -> vector<int>
            {
                return { args[0] - args[1] };
            }
        )
        .Map(
            [](int arg) -> int
            {
                return arg + 1;
            }
        );
    
    exp.Eval({ 2, 4, 5 });
}