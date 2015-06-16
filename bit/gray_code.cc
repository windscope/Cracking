// Authour windscope <windscope@gmail.com>
// Problem: Gray Code
// The gray code is a binary numeral system where two successive values differ in only one bit.
// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
// For example, given n = 2, return [0,1,3,2]

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
vector<int> grayCode(int n) {
    vector<int> result;
    result.push_back(0);
    if (n == 0) {
        return result;
    }
    for (int i = 0; i < n; ++i) {
        size_t count = result.size();
        for( size_t j = 1; j <= count; ++j) {
            result.push_back(result[count - j] + (1<<(i)));
        }
    }
    return result;
}
};

int main(int argc, char* argv[]) {
    if (argc > 2)
        return 1;
    Solution s;
    vector<int> result = s.grayCode(atoi(argv[1]));
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
