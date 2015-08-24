// Find Minimum in Rotated Sorted Array II
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int findMin(const vector<int>& nums) {
        uint32_t start = 0;
        uint32_t end = nums.size() - 1;
        while (start < end) {
            // cout << "start1: " << start << ", end1: " << end << endl;
            if (nums[start] < nums[end]) {
                return nums[start];
            } else {
                int mid  = (start + end) / 2;
                if (nums[mid] > nums[start]) {
                    start = mid + 1;
                } else if (nums[mid] < nums[start]) {
                    end = mid;
                } else {
                    // if start and the mid are the same, we proceed all the duplicated starts
                    do {
                        start++;
                    } while(start + 1 < end && nums[start] == nums[start + 1]);
                }
            }
            // cout << "start2: " << start << ", end2: " << end << endl;
        }
        // cout << "result: " << nums[start] << ", " << nums[end] << endl;
        return min(nums[start], nums[end]);
    }
};

int main() {
    vector<vector<int>> datas = {
        {1, 1, 3, 4, 5, 0},
        {5, 5, 5, 2, 3, 4},
        {1},
        {1, 2, 2, 3, 3, 3, 1, 1},
        {1, 1, 1, 1, 1},
        {3, 1, 3},
        {10, 1, 10, 10, 10}
    };
    vector<int> expected_result = {0, 2, 1, 1, 1, 1, 1};
    Solution s;
    int count  = 0;
    for (auto data : datas) {
        assert(s.findMin(data) == expected_result[count++]);
    }
    cout << "You Passed!" << endl;
    return 0;
}
