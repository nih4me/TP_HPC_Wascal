
#include "include/rapidcsv.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {

    rapidcsv::Document doc("data/newdata.csv", rapidcsv::LabelParams(0, 0));
    size_t total_data = doc.GetRowCount();

    for (int i = 0; i < total_data; i++) {
        // vector<float> row = doc.GetRow<float>("" + to_string(i + 1)); OR
        vector<float> row = doc.GetRow<float>(i);
        for (auto i = row.begin(); i != row.end(); ++i) {
            cout << *i << "\t";
        }
        cout << endl;
    }

    return 0;
}
