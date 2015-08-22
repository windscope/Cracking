// Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int two_d_to_one_d(const int x, const int y, const int m, const int n){
        return x + y * n;
    }

    vector<int> one_d_to_two_d(const int a, const int m, const int n) {
        return { a / n, a % n };
    }

    int acess_data_via_one_d(const int a, const int m, const int n, const vector<vector<int>>& matrix) {
        vector<int> pair = one_d_to_two_d(a, m, n);
        return matrix[pair[0]][pair[1]];
    }

    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[m-1].size();
        if (m == 0 | n == 0) {
            return false;
        }
        return search_matrix_helper(matrix, target, 0, two_d_to_one_d(n - 1, m - 1, m, n));
    }

    bool search_matrix_helper(
            const vector<vector<int>>& matrix,
            const int target,
            const int lower,
            const int upper) {
        int m = matrix.size();
        int n = matrix[m-1].size();
        if (lower > upper) {
            return false;
        } else if (lower + 1 == upper) {
            return (acess_data_via_one_d(lower, m, n, matrix) == target) || (acess_data_via_one_d(upper, m, n, matrix) == target);
        }
        int next_bound = (lower + upper) / 2;
        int next_bound_data = acess_data_via_one_d(next_bound, m, n, matrix);
        if (next_bound_data == target) {
            return true;
        } else if (next_bound_data > target) {
            return search_matrix_helper(matrix, target, lower, next_bound);
        } else {
            return search_matrix_helper(matrix, target, next_bound, upper);
        }
    }


};

int main() {
    vector<vector<int>> test_data = {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    Solution s;
    assert(s.searchMatrix(test_data, 5));
    assert(s.searchMatrix(test_data, 10));
    assert(s.searchMatrix(test_data, 23));
    assert(!s.searchMatrix(test_data, 21));
    cout << "You Passed!" << endl;
    return 0;
}
