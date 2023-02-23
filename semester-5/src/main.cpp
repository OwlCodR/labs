#include "iostream"
#include "expression/expression.h"
#include "utils/log.h"
#include <string>

#include <thread>
#include <chrono>

using namespace std;

#define TAG string("MAIN\t\t\t")

int main() {
    Expression<int> exp = Expression<int>({ 0, 10, 2, 34 })
        .Every(
            {
                [](vector<int> args) -> int
                {
                    Debug(TAG, "Start Every 1");
                    this_thread::sleep_for(500ms);
                    Debug(TAG, "Finish Every 1");
                    return 1;
                },
                [](vector<int> args) -> int
                {
                    Debug(TAG, "Start Every 2");
                    this_thread::sleep_for(500ms);
                    Debug(TAG, "Finish Every 2");
                    return 2;
                },
                [](vector<int> args) -> int
                {
                    Debug(TAG, "Start Every 3");
                    this_thread::sleep_for(500ms);
                    Debug(TAG, "Finish Every 3");
                    return 3;
                },
                [](vector<int> args) -> int
                {
                    Debug(TAG, "Start Every 4");
                    this_thread::sleep_for(500ms);
                    Debug(TAG, "Finish Every 4");
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
        .JoinValues({ 2, 4, 6 })
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
                return { args[0], 65, 100 };
            }
        )
        .Switch(
            [](vector<int> args) -> int { return args[1]; }
        )
        .Case(
            65,
            [](vector<int> args) -> vector<int> { return { 1 }; }
        )
        .Case(
            10,
            [](vector<int> args) -> vector<int> { return { 2 }; }
        )
        .Default(
            [](vector<int> args) -> vector<int> { return { 4 }; }
        )
        .JoinValues({ -10, 1, 10 })
        .All(
            [](int arg) -> bool { return arg > 0; }
        );
    
    exp.EvalAsync({ 2, 4, 5 });
}