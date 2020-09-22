#include <cmath>

using namespace std;

int main() {
    const int size = 256;
    double sinTable[size];
    
    #pragma omp simd
    for(int n = 0; n < size; ++n) {
        sinTable[n] = sin(2 * M_PI * n / size);
    }
  
    // the table is now initialized
}