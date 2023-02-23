#ifndef FUNCTION_TYPES_H
#define FUNCTION_TYPES_H

#define ResultFunctionType function<vector<T>(vector<T>)>
#define IfFunctionType function<bool(vector<T>)>
#define MapFunctionType function<T(T)>
#define EveryFunctionType function<T(vector<T>)>
#define ProjectFunctionType function<T(T)>
#define SwitchFunctionType function<T(vector<T>)>
#define AllFunctionType function<bool(T)>

#endif