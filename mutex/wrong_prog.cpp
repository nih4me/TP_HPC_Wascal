#include <queue>
#include <thread>
#include <iostream>

using namespace std;

void addOne(int& b) {
    b = b + 1;
}

int main() {
    int b = 5;

    thread tA(addOne, std::ref(b));
    thread tB(addOne, std::ref(b));
    tA.join();
    tB.join();

    cout << b << endl;
}
