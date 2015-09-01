// implement merge sort

#include <vector>
#include <iostream>
using namespace std;

void print_data(const vector<int>& data) {
    for (auto d : data) {
        cout << d << ",";
    }
    cout << endl;
}

class MergeSort {
public:
    void merge(vector<int>& data, int p, int q, int r) {
        vector<int> left(data.begin() + p, data.begin() + q + 1);
        vector<int> right(data.begin() + q + 1, data.begin() + r + 1);
        int k = p;
        int l = 0;
        int m = 0;
        while (k <= r && l < left.size() && m < right.size()) {
            if (left[l] < right[m]) {
                data[k] = left[l];
                ++l;
            } else {
                data[k] = right[m];
                ++m;
            }
            ++k;
        }
        while (l < left.size()) {
            data[k] = left[l];
            ++l;
            ++k;
        }
        while (m < right.size()) {
            data[k] = right[m];
            ++k;
            ++m;
        }

    }
    void divider(vector<int>& data, int p, int r) {
        if (p < r) {
            int q = (p + r) / 2;
            divider(data, p, q);
            divider(data, q + 1, r);
            merge(data, p, q, r);
        }
    }
    void sort(vector<int>& data) {
        divider(data, 0, data.size() - 1);
    }
};



int main() {
    MergeSort sorter;
    vector<int> data = {2, 3, 5, 6, 7, 4, 3 ,1, 9, 11, 23, 5, 4, 3};
    sorter.sort(data);
    print_data(data);
}
