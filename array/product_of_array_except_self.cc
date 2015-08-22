#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }
        vector<int> ret(nums.size(), 1);

        for (uint32_t i = 1; i < nums.size(); ++i) {
            ret[i] = nums[i - 1] * ret[i - 1];
        }
        int acc = 1;
        for (uint32_t i = nums.size() - 1; i > 0; --i) {
            acc *= nums[i];
            ret[i-1] = ret[i-1] * acc;
        }
        return ret;
    }
};

int main() {
    vector<int> test_data = {1, 2, 3, 4};
    vector<int> expeceted_data = {24, 12, 8, 6};
    Solution s;
    std::vector<int> result = s.productExceptSelf(test_data);
    for(uint32_t i = 0; i < test_data.size(); ++i) {
        assert(expeceted_data[i] == result[i]);
    }
    cout << "You Passed!" << endl;
}
