#include "iostream"
#include "expression/expression.h"
#include "utils/log.h"
#include <string>

#include <thread>
#include <chrono>

using namespace std;

#define TAG string("MAIN\t\t\t")

#define calculationTime 500ms

int main() {
    Expression<int> exp = Expression<int>({ 0, 10, 2, 34 })
        .Every(
            {
                [](vector<int> args) -> int
                {
                    Debug(TAG, "Start Every 1");
                    this_thread::sleep_for(calculationTime);
                    Debug(TAG, "Finish Every 1");
                    return 1;
                },
                [](vector<int> args) -> int
                {
                    Debug(TAG, "Start Every 2");
                    this_thread::sleep_for(calculationTime);
                    Debug(TAG, "Finish Every 2");
                    return 2;
                },
                [](vector<int> args) -> int
                {
                    Debug(TAG, "Start Every 3");
                    this_thread::sleep_for(calculationTime);
                    Debug(TAG, "Finish Every 3");
                    return 3;
                },
                [](vector<int> args) -> int
                {
                    Debug(TAG, "Start Every 4");
                    this_thread::sleep_for(calculationTime);
                    Debug(TAG, "Finish Every 4");
                    return 4;
                },
            }
        )
        .Project(
            {
                [](int arg1) -> int
                {
                    this_thread::sleep_for(calculationTime);
                    return 4;
                },
                [](int arg2) -> int
                {
                    this_thread::sleep_for(calculationTime);
                    return NULL;
                },
                [](int arg3) -> int
                {
                    this_thread::sleep_for(calculationTime);
                    return 2;
                },
                [](int arg4) -> int
                {
                    this_thread::sleep_for(calculationTime);
                    return 1;
                },
            }
        )
        .JoinValues({ 2, 4, 6 })
        .If(
            [](vector<int> args) -> bool
            { 
                this_thread::sleep_for(calculationTime);
                return args[0] > args[1];
            }
        )
        .Then(
            [](vector<int> args) -> vector<int>
            { 
                this_thread::sleep_for(calculationTime);
                return { args[0] + args[1] };
            }
        )
        .Else(
            [](vector<int> args) -> vector<int>
            {
                this_thread::sleep_for(calculationTime);
                return { args[0] - args[1] };
            }
        )
        .Map(
            [](int arg) -> int
            {
                this_thread::sleep_for(calculationTime);
                return arg + 1;
            }
        )
        .Then(
            [](vector<int> args) -> vector<int>
            {
                this_thread::sleep_for(calculationTime);
                args[0] = args[0] + 100;
                return { args[0], 65, 100 };
            }
        )
        .Switch(
            [](vector<int> args) -> int { 
                this_thread::sleep_for(calculationTime);
                return args[1]; 
            }
        )
        .Case(
            65,
            [](vector<int> args) -> vector<int> {
                this_thread::sleep_for(calculationTime);
                return { 1 }; 
            }
        )
        .Case(
            10,
            [](vector<int> args) -> vector<int> { 
                this_thread::sleep_for(calculationTime);
                return { 2 }; 
            }
        )
        .Default(
            [](vector<int> args) -> vector<int> { 
                this_thread::sleep_for(calculationTime);
                return { 4 }; 
            }
        )
        .JoinValues({ -10, 1, 10 })
        .All(
            [](int arg) -> bool { 
                Debug(TAG, "Start All " + to_string(arg));
                this_thread::sleep_for(calculationTime);
                Debug(TAG, "Finish All " + to_string(arg));
                return arg > 0;
            }
        )
        .Any(
            [](int arg) -> bool { 
                Debug(TAG, "Start Any " + to_string(arg));
                this_thread::sleep_for(calculationTime);
                Debug(TAG, "Finish Any " + to_string(arg));
                return arg > 0;
            }
        );
    
    auto begin = chrono::high_resolution_clock::now();
    exp.Eval({ 2, 4, 5 });
    auto end = chrono::high_resolution_clock::now();
    auto diff1 = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    Info(TAG, "Sync: " + to_string(diff1) + " ms");

    begin = chrono::high_resolution_clock::now();
    exp.EvalAsync({ 2, 4, 5 });
    end = chrono::high_resolution_clock::now();
    auto diff2 = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    
    Info(TAG, "Async: " + to_string(diff2) + " ms");
}