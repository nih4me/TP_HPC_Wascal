#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define M 100000
#define N 100000

int A[M][N];

int main () {
    
    int c = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i * j;
            c = c + 1;
        }
    }

    cout << "Main : " << c << " Initializations" << endl;
}