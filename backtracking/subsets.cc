// backtracking is dfs + mesuarement, solve problems that are 1. require order 2. has a mesurement
// https://leetcode.com/problems/subsets/
// Subsets Total Accepted: 60552 Total Submissions: 214339 My Submissions Question Solution
// Given a set of distinct integers, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
#include <iostream>
#include <vector>

using namespace std;

// without duplicates
class Solution1 {
public:
    using Matrix = vector<vector<int>>;
    Matrix subsets(vector<int>& nums) {
        Matrix result;
        result.push_back({});
        if (nums.size() == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (uint32_t i = 0; i < nums.size(); ++i) {
            vector<int> data = {nums[i]};
            result.push_back(data);
            dfs_traverse(i, nums, data, result);
        }
    }
    void dfs_traverse(const int index, const vector<int>& nums, const vector<int>& data, Matrix& result) {
        int i = index;
        vector<int> data_copy = data;
        while (i + 1< nums.size()) {
            i += 1;
            data_copy.push_back(nums[i]);
            result.push_back(data_copy);
            dfs_traverse(i, nums, data_copy, result);
            data_copy.pop_back();
        }
    }
};

// with duplicates
class Solution2 {
public:
    using Matrix = vector<vector<int>>;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        Matrix result;
        result.push_back({});
        if (nums.size() == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (uint32_t i = 0; i < nums.size(); ++i) {
            vector<int> temp = {nums[i]};
            result.push_back(temp);
            dfs_traverse(i, nums, temp, result);
            // a very important pattern, remove all duplicate from start
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return result;
    }

    void dfs_traverse(const int index, const vector<int>& nums, const vector<int>& prev_data, Matrix& result) {
        int i = index;
        vector<int> next_data = prev_data;
        while (++i < nums.size()) {
            next_data.push_back(nums[i]);
            result.push_back(next_data);
            dfs_traverse(i, nums, next_data, result);
            next_data.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
    }
};
