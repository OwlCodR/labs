#ifndef UI_H
#define UI_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;

class UI {
public:
    UI() {

    }

    UI(map<string, function<void()>> functions) {
        this->functions = functions;
    }

    UI(string title) {
        this->title = title;
    }

    void printMenu() {
        cout << getTitle() << endl;

        map<string, function<void()>>::iterator it = functions.begin();
        for (int i(0); it != functions.end(); it++, i++) {
            cout << i + 1 << ". " << it->first << endl;
        }
    }

    void start() {
        while (true) {
            printMenu();

            int choice;

            cout << "Choice: "; 
            cin >> choice;

            map<string, function<void()>>::iterator it = functions.begin();
            for (int i(0); it != functions.end(); i++, it++) {
                if (choice == i + 1) {
                    it->second();
                }
            }
        }
    }

    void setTitle(string title) {
        this->title = title;
    }

    string getTitle() {
        return this->title;
    }

private:
    map<string, function<void()>> functions;
    string title;
};

#endif