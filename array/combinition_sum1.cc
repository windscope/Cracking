// https://leetcode.com/problems/combination-sum/
// Algorith:
//          dfs, backtrace
// Lessons learnt:
//          1. pay attention to the initializatio step of dfs, duplicated loop may happen
//          2. pay attention to the dfs variable, remember to make them stay invariance if needed
// Score: 24ms
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

class Solution {
public:
    typedef std::vector<std::vector<int>> int_vector_2d;
    typedef std::vector<int>::const_iterator vint_cit_t;
    int_vector_2d combinationSum(std::vector<int>& candidates, int target) {
        int_vector_2d ret;
        std::vector<int> data;
        std::sort(candidates.begin(), candidates.end());
        dfs_traverse(0, data, candidates.begin(), candidates.end(), target, &ret);
        return ret;
    }

    void dfs_traverse(const int pre_sum, std::vector<int> data,
            vint_cit_t begin, vint_cit_t end, const int target, int_vector_2d* ret) {
        for (auto it = begin; it < end; ++it) {
            if (pre_sum + *it == target) {
                data.push_back(*it);
                ret->push_back(data);
                data.pop_back();
            } else if (pre_sum + *it < target) {
                data.push_back(*it);
                dfs_traverse(pre_sum + *it, data, it, end, target, ret);
                data.pop_back();
            }
        }
    }

};

void print_2dvec(const Solution::int_vector_2d& data) {
    for (int j = 0; j < data.size(); ++j) {
        std::vector<int> item = data[j];
        for (int i = 0; i < item.size(); ++i) {
            std::cout << item[i] << ",";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> test_data = {1, 2, 3, 5};
    Solution s;
    Solution::int_vector_2d result = s.combinationSum(test_data, 8);
    print_2dvec(result);
    assert(result.size() == 13);
    std::cout << "passed" << std::endl;
    return 0;
}
