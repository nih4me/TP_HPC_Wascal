#include "include/rapidcsv.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {

    rapidcsv::Document doc("data/GlobalLandTemperaturesByCity.csv", rapidcsv::LabelParams(0, 0));
    size_t total_data = doc.GetRowCount();

    vector<int> v;
    cout << "Vector<int> maximum size : " << v.max_size() << endl;

    vector<float> v0;
    cout << "Vector<float> maximum size : " << v0.max_size() << endl;

    vector<string> v1;
    cout << "Vector<string> maximum size : " << v1.max_size() << endl;

    cout << total_data << endl;

    return 0;
}
