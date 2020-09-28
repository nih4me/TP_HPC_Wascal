#include <iostream>

using namespace std;

int main() {

    // load and process CSV file

    // Save results in test.dat file
    string toplot;

    cout << "filename : ";
    cin >> toplot;

    // Plot results using instructions in my_plot.dem
    string p = "gnuplot ";
    system(p.append(toplot).c_str());

    return 0;
}