#include <iostream>
#include <vector>
#include "include/rapidcsv.h"

using namespace std;

int main() {

    rapidcsv::Document doc("data/colrowhdr.csv", rapidcsv::LabelParams(0, 0));

    vector<float> close = doc.GetRow<float>("2017-02-22");
    for (auto i = close.begin(); i != close.end(); ++i) {
        cout << *i << endl;
    }

    long long volume = doc.GetCell<long long>("Volume", "2017-02-22");
    cout << "Volume " << volume << " on 2017-02-22." << endl;

    return 0;
}