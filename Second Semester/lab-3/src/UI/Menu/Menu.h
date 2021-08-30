#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <functional>

class Menu
{
public:
    void start();
    void addFunction(string description, function<void()> f);
private:
    vector<pair<string, function<void()>>> items;
};

#endif