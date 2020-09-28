

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

void changeA(int n) {
    n = n * n;
    cout << n << end;
}

int main () {
   int a = 10;

   changeA(a);

   cout << a << end;
}