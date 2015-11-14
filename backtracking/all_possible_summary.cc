// given a vector of int [1, 2, 3], and two operator [+, -]
// you should get result:

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> allPossibleSummary(const vector<int>& nums) {
        unordered_set<int> result_set;
        backTracking(nums, result_set, 0, 0, true);
        vector<int> results(result_set.begin(), result_set.end());
        return results;
    }

    void backTracking(const vector<int>& nums, unordered_set<int>& results, int prevSum, int pos, bool allNeg) {
        if (pos == nums.size()) {
            if (!allNeg) {
                results.insert(prevSum);
            }
            return;
        }
        backTracking(nums, results, prevSum + nums[pos], pos + 1, false);
        backTracking(nums, results, prevSum - nums[pos], pos + 1, allNeg);
    }
};


int main(void) {
    vector<int> data = {1, 2, 3};
    Solution s;
    vector<int> results = s.allPossibleSummary(data);
    for (auto result : results) {
        cout << result << endl;
    }
    return 0;
}
