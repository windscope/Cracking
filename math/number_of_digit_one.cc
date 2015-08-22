#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int countDigitOne(const int n) {
        int64_t higher_digit = 0;
        int64_t lower_digit = 0;
        int64_t ret = 0;
        for (int64_t m = 1; m <= n; m *= 10) {
            higher_digit = n / m;
            lower_digit = n % m;
            if (higher_digit % 10 > 1) {
                ret += (higher_digit / 10 + 1) * m;
            } else if (higher_digit % 10 == 1) {
                ret += higher_digit / 10 * m + lower_digit + 1;
            } else {
                ret += (higher_digit / 10) * m;
            }
        }
        return static_cast<int>(ret);
    }
};

int main() {
    Solution s;
    vector<int> test_data = {13, 23, 1, 2, 10, 101};
    vector<int> expected_result = {6, 13, 1, 1, 2, 23};
    for (uint32_t i = 0; i < test_data.size(); ++i) {
        assert(s.countDigitOne(test_data[i]) == expected_result[i]);
    }
    cout << "You Passed!" << endl;
    return 0;
}
