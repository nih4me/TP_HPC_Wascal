
#include "include/rapidcsv.h"
#include <vector>
#include <iostream>

using namespace std;


int main() {

    rapidcsv::Document doc("data/colhdr.csv");

    vector<float> col = doc.GetColumn<float>("Close");

    // calculate
    int n_correct = 0;
    float s = 0.0;
    float m = 0.0;
    for (auto i = col.begin(); i != col.end(); ++i) {
        if (!isnan(*i)) {
            n_correct = n_correct + 1;
            s = s + *i;
        }
    }
    m = s/n_correct;

    // replace
    for (auto i = col.begin(); i != col.end(); ++i) {
        if (isnan(*i)) {
            *i = m;
        }
    }

    // display
    for (auto i = col.begin(); i != col.end(); ++i) {
        cout << *i << endl;
    }

    return 0;
}