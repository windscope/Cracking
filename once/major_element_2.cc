#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> ret;
        int major[2] = {INT_MIN, INT_MAX};
        int count[2] = {0, 0};
        for (const auto& num : nums) {
            if (num == major[0]) {
                ++count[0];
            } else if (num == major[1]) {
                ++count[1];
            } else if (count[0] == 0 && major[1] != num){
                major[0] = num;
                count[0] = 1;
            } else if (count[1] == 0 && major[0] != num) {
                major[1] = num;
                count[1] = 1;
            } else {
                --count[0];
                --count[1];
            }
        }
        // check whehther correct
        for (const auto& m : major) {
            int count = 0;
            for (const auto& num : nums) {
                if (num == m){
                    count += 2;
                } else {
                    --count;
                }
            }
            if (count > 0) {
                ret.push_back(m);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> data = {1,2,3,1};
    vector<int> result = s.majorityElement(data);
    for (auto r : result) {
        cout << r << ", ";
    }
    cout << endl;
}