// https://leetcode.com/problems/reverse-integer/
// Reverse digits of an integer.
// Example1: x = 123, return 321
// Example2: x = -123, return -321

// lesson learnt:
//        considering overflow

#include <cassert>
#include <vector>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0 || x >= INT_MAX || x <= INT_MIN) {
            return 0;
        }
        int ret = x % 10;
        while (abs(x) >= 10) {
            if (ret > INT_MAX / 10 || ret < INT_MIN / 10) return 0;
            x /= 10;
            ret = ret * 10 + x % 10;
        }
        return ret;
    }
};

int main() {
    vector<int> test_data = { 123, -123, 10, 1, 1001, 10000, -2147483648};
    vector<int> validation_data = { 321, -321, 1, 1, 1001, 1, 0};
    Solution s;
    for (int i = 0; i < test_data.size(); ++i) {
        // cout << i << endl;
        // cout << "ret = " << s.reverse(test_data[i]) << endl;
        assert(s.reverse(test_data[i]) == validation_data[i]);
    }
    cout << "passed" << endl;
}
