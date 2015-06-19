// Sourece https://leetcode.com/problems/3sum-closest
/* Problem: Given an array S of n integers, find three integers in S such that the sum is closest
 * to a given number, target. Return the sum of the three integers. You may assume that each input
 * would have exactly one solution.
 */

#include <cassert>
#include <algorithm>
#include <iostream>

 using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) {
                return ret;
            }
        }

    }
};
