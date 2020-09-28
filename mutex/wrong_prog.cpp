#include <queue>
#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

void addOne(int& b, mutex& m) {
    m.lock();
    b = b + 1;
    m.unlock();
}

int main() {
    int b = 5;
    mutex m;

    thread tA(addOne, std::ref(b), std::ref(m));
    thread tB(addOne, std::ref(b), std::ref(m));
    thread tC(addOne, std::ref(b), std::ref(m));
    thread tD(addOne, std::ref(b), std::ref(m));
    tA.join();
    tB.join();
    tC.join();
    tD.join();

    cout << b << endl;
}
