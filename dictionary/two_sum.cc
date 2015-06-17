#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        auto it = _dict.find(nums[i]);
        if (it == _dict.end()) {
            _dict[target - nums[i]] = i;
        } else {
            return vector<int> {it->second + 1, i + 1};
        }
    }
    return vector<int> {0,0};
}
private:
unordered_map<int, int> _dict;

};

int main() {
    Solution s;
    vector<int> data1 = {1,2,3,4,5,6,7,8,9};
    vector<int> ret = s.twoSum(data1, 17);
    cout << ret[0] << endl << ret[1] << endl;
    assert(ret[0] == 8);
    assert(ret[1] == 9);
    return 0;
}
