// Jump Game II Total Accepted: 46810 Total Submissions: 193891 My Submissions Question Solution
// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// For example:
// Given array A = [2,3,1,1,4]

// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        if (nums[0] > nums.size() - 2) return 1;
        int step = 1;
        int start_index = 0;
        int tail_index = 0;
        do {
            start_index = find_max_index(nums, tail_index + 1, start_index + nums[start_index]);
            tail_index = start_index + nums[start_index];
            if (nums[start_index] > 0) {
                step++;
            } else {
                return step;
            }
        } while (tail_index < nums.size());
        return step;
    }

    int find_max_index (const vector<int>& nums, const int m, const int n) {
        int max_num = 0;
        int max_index = m;
        for (int i = m; i <= n; ++i) {
            if (nums[i] > max_num) {
                max_num = nums[i];
                max_index = i;
            }
        }
        return max_index;
    }
};

int main() {
    vector<int> data = {1, 2, 0, 1};
    Solution s;
    cout << s.jump(data) << endl;
    return 0;
}
