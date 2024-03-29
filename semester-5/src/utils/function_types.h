#ifndef FUNCTION_TYPES_H
#define FUNCTION_TYPES_H

#define ResultFunctionType function<vector<T>(vector<T>)>
#define IfFunctionType function<bool(vector<T>)>
#define MapFunctionType function<T(T)>
#define EveryFunctionType function<T(vector<T>)>
#define ProjectFunctionType function<T(T)>
#define SwitchFunctionType function<T(vector<T>)>
#define FilterFunctionType function<bool(T)>
#define FoldFunctionType function<T(T, T)>

#endif