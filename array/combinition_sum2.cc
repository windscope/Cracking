// https://leetcode.com/problems/combination-sum-ii/
// Algorith:
//          dfs, backtrace
// lessons to learn:
//          1. remember to remove duplicated numbers in the data
//          2. Remember the difference between continue and break
// Score: 20ms

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

class Solution {
public:
    typedef std::vector<std::vector<int> > int_2dv_t;
    typedef std::vector<int>::const_iterator int_v_cit_t;
    int_2dv_t combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<int> data;
        int_2dv_t ret;
        std::sort(candidates.begin(), candidates.end());
        dfs_traverse(0, data, target, candidates.begin(), candidates.end(), &ret);
        return ret;
    }
    void dfs_traverse(const int pre_sum, std::vector<int> data, const int target,
            int_v_cit_t begin, int_v_cit_t end, int_2dv_t* ret) {
        for (auto it = begin; it < end; ++it) {
           if (it > begin && *it == *(it - 1)) {
                continue;
            }
            if (*it + pre_sum == target) {
                data.push_back(*it);
                ret->push_back(data);
                data.pop_back();
            } else if (*it + pre_sum < target) {
                data.push_back(*it);
                dfs_traverse(*it + pre_sum, data, target, it + 1, end, ret);
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
    std::vector<int> data = {10, 1, 2, 7, 6, 1, 5, 8};
    Solution s;
    Solution::int_2dv_t ret = s.combinationSum2(data, 8);
    print_2dvec(ret);
    return 0;
}
