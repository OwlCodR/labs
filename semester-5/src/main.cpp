#include "iostream"
#include "expression/expression.h"

using namespace std;

int main() {
    Expression<int>().value({2, 1, 2})
        .If(
            [](vector<int> args) 
            { 
                return args[0] > args[1]; 
            }
        )
        .Then(
            [](vector<int> args) 
            { 
                return args[0] + args[1];
            }
        )
        .Else(
            [](vector<int> args)
            {
                return args[0] - args[1];
            }
        );
}