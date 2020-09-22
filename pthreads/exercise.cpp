

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define M 10000
#define N 10000
#define NUM_THREADS 5

struct thread_data {
    int id;
    int startI;
};

int A[M][N];
int count = M / NUM_THREADS;

void *initArray(void *threadarg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;

    int c = 0;
    int end = my_data->startI + count;
    for (int i = my_data->startI; i < end; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i * j;
            c = c + 1;
        }
    }

    cout << "Thread with ID = " << my_data->id << " : " << c << " Initializations" << endl;

    pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   struct thread_data data[NUM_THREADS];
   
   int rc;
   int i;

   for( i = 0; i < NUM_THREADS; i++ ) {
        
        data[i].id = i;
        data[i].startI = i * count;
        // if i = 0 startI = 0 * 2000 = 0 ; if i = 1 startI = 1 * 2000 = 2000 ; i = 4 startI = 4 * 2000 = 8000
        rc = pthread_create(&threads[i], NULL, initArray, (void *)&data[i]);
      
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
   }

   pthread_exit(NULL);
}