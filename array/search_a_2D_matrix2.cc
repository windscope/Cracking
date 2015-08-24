// Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/
// Algorithm: remeber to count from back(inverse iteration)
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    typedef vector<vector<int>> matrix_t;
    bool searchMatrix(const matrix_t& matrix, const int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = 0;
        int n = matrix[0].size() - 1;
        while (matrix[m][n] != target) {
            if (matrix[m][n] > target) {
                n--;
            } else {
                m++;
            }
            if (m >= matrix.size() || n < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    Solution::matrix_t test_data = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   7,  9, 16, 22},
        {10, 13, 22, 17, 24},
        {18, 21, 23, 26, 30}
    };
    vector<int> true_results = {1, 4, 5, 9, 26, 30, 18};
    vector<int> false_results = {31, 0, 14, 6};
    for (auto item : true_results) {
        assert(s.searchMatrix(test_data, item));
    }
    for (auto item : false_results) {
        assert(!s.searchMatrix(test_data, item));
    }
    cout << "You Passed" << endl;
    return 0;
}
