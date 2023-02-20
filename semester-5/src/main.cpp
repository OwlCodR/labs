#include "iostream"
#include "expression.h"
#include "log.h"

using namespace std;

#define TAG "MAIN\t\t\t"

int main() {
    Expression<int> exp = Expression<int>().value({ 0, 10 })
        .Every(
            {
                [](vector<int> args) -> int
                {
                    return 1;
                },
                [](vector<int> args) -> int
                {
                    return 2;
                },
                [](vector<int> args) -> int
                {
                    return 3;
                },
                [](vector<int> args) -> int
                {
                    return 4;
                },
            }
        )
        .Project(
            {
                [](int arg1) -> int
                {
                    return 4;
                },
                [](int arg2) -> int
                {
                    return NULL;
                },
                [](int arg3) -> int
                {
                    return 2;
                },
                [](int arg4) -> int
                {
                    return 1;
                },
            }
        )
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
        )
        .Then(
            [](vector<int> args) -> vector<int>
            {
                args[0] = args[0] + 100;
                return args;
            }
        );
    
    exp.Eval({ 2, 4, 5 });
}