#include "Menu.h"

void Menu::start() {
    cout << "\n\n\n= = = MENU = = =" << endl;
    for (int i(0); i < items.size(); i++) {
        cout << i << ". " << items[i].first << endl;
    }

    int answer;
    cout << "Number: ";
    cin >> answer;

    for (int i(0); i < items.size(); i++) {
        if (answer == i) {
            items[i].second();
        }
    }

    start();
}

void Menu::addFunction(string description, function<void()> f) {
    pair<string, function<void()>> newPair(description, f);
    items.push_back(newPair);
}