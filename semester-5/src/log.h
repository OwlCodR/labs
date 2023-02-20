#ifndef LOG_H
#define LOG_H

#define DEBUG
#define WARNING

#ifdef DEBUG
#define Debug(tag, msg) cout << "DEBUG\t| " << tag << " | " << msg << endl;
#else
#define Debug(tag, msg)
#endif

#ifdef WARNING
#define Warning(tag, msg) cout << "WARNING\t| " << tag << " | " << msg << endl;
#else
#define Warning(tag, msg)
#endif


#include <string>

template<class T>
std::string argsToString(vector<T> args) {
    std::string s = " ";
    s += "{ ";
    for (int i = 0; i < args.size(); i++) {
        s += std::to_string(args[i]);
        if (i != args.size() - 1) {
            s += ", ";
        }
    }
    s += " }";
    return s;
};

#endif