#include "iostream"
#include "expression/expression.cpp"

using namespace std;

int main() {
    cout << Expression<int>().value(2, 1, 2).values.size() << endl;
    return 0;
}