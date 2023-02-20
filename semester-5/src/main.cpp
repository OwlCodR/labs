#include "iostream"
#include "expression.h"

using namespace std;

int main() {
    Expression<int> exp = Expression<int>().value({ 2, 1, 2 })
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
        );
    cout << exp.actions.size() << endl;
}