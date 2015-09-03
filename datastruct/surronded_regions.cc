// Surrounded Regions Total Accepted: 36059 Total Submissions: 243833 My Submissions Question Solution
// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using Grid = vector<vector<char>>;
public:
    void solve(Grid& board) {
        if (board.size() <= 2 || board.begin()->size() <= 2) {
            return;
        }
        int m = board.size();
        int n = board.begin()->size();
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                dfs_traverse(board, i, 0, m, n);
            }
            if (board[i][n - 1] == 'O') {
                dfs_traverse(board, i, n - 1, m, n);
            }
        }
        for (int j = 1; j < n - 1; ++j) {
            if (board[0][j] == 'O') {
                dfs_traverse(board, 0, j, m, n);
            }
            if (board[m - 1][j] == 'O') {
                dfs_traverse(board, m - 1, j, m, n);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs_traverse(Grid& board, int i, int j, const int m, const int n) {
        board[i][j] = '1';
        if (i > 1 && board[i - 1][j] == 'O') {
            dfs_traverse(board, i - 1, j, m, n);
        }
        if (i < m - 2 && board[i + 1][j] == 'O') {
            dfs_traverse(board, i + 1, j, m, n);
        }
        if (j > 1 && board[i][j - 1] == 'O') {
            dfs_traverse(board, i, j - 1, m, n);
        }
        if (j < n - 2 && board[i][j + 1] == 'O') {
            dfs_traverse(board, i, j + 1, m, n);
        }
        // cout << "i: " << i << ", j: " << j << ", board[i][j]: " << board[i][j] << endl;
    }
};

int main() {
    Solution s;
    Solution::Grid test_data1 = {
        {'X', 'X', 'X', 'O'},
        {'X', 'O', 'O', 'X'},
        {'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X'}
        // {'O', 'O'},
        // {'O', 'O'}
    };
    s.solve(test_data1);
    for (const auto& data : test_data1) {
        for (auto d : data) {
            cout << d << ",";
        }
        cout << endl;
    }
    return 0;
}
