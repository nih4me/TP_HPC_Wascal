

#include <iostream>

using namespace std;

void change(int a) {
    a = a * a;
    cout << "inner the function" << endl;
    cout << n << endl;
}

int main () {
    int a = 10;

    change(a);

    cout << "outside the function" << endl;
    cout << a << endl;
}