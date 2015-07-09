// https://leetcode.com/problems/combination-sum-iii/
// Find all possible combinations of k numbers that add up to a number n, given that only numbers
// from 1 to 9 can be used and each combination should be a unique set of numbers.
// Ensure that numbers within the set are sorted in ascending order.
// Algorith:
//          dfs, backtrace
// Score:  4 ms

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    typedef vector<vector<int>> int_2dv_t;
    typedef vector<int>::const_iterator int_vcit_t;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidate = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> data;
        int_2dv_t ret;
        dfs_traverse(0, 0, n, k, data, candidate.begin(), candidate.end(), &ret);
        return ret;
    }
    void dfs_traverse(const int pre_sum, const int depth, const int target, const int target_depth,
            vector<int> data, int_vcit_t begin, int_vcit_t end, int_2dv_t* ret) {
        for (auto it = begin; it < end; ++it) {
            if (depth + 1 == target_depth && pre_sum + *it == target) {
                data.push_back(*it);
                ret->push_back(data);
                break;
            } else if (pre_sum + *it >= target) {
                break;
            } else {
                data.push_back(*it);
                dfs_traverse(pre_sum + *it, depth + 1, target, target_depth, data, it + 1, end, ret);
                data.pop_back();
            }
        }
    }
};

namespace {

void print_1dvect(const std::vector<int>& data) {
    for (const auto& item : data) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;
}

void print_2dvec(const Solution::int_2dv_t& data) {
    for (const auto& item : data) {
        print_1dvect(item);
    }
}

} // anonymous namespace

int main() {
    Solution s;
    Solution::int_2dv_t ret = s.combinationSum3(3, 9);
    print_2dvec(ret);
    return 0;
}
