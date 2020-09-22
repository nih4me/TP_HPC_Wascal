#include <iostream>

using namespace std;

int main() {

    // 0 -> false
    // > 0 -> true
    
    bool enabled_parallel = false;
    // #pragma omp parallel if(enabled_parallel)


    #pragma omp parallel num_threads(3)
    {
        cout << "Hello" << endl;
    }

    #pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
    }
}