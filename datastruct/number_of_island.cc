// Number of Islands
// https://leetcode.com/problems/number-of-islands/
// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally
// or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:
// 11110
// 11010
// 11000
// 00000
// Answer: 1

// Example 2:
// 11000
// 11000
// 00100
// 00011
// Answer: 3

// DFS, union find

#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    using Grid = vector<vector<char>>;
    int numIslands(Grid& grid) {
        int count = 0;
        if (grid.size() == 0 || grid.begin()->size() ==0) {
            return count;
        }
        int m = grid.size();
        int n = grid[m - 1].size();
        vector<vector<bool>> is_visited;
        is_visited.resize(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !is_visited[i][j]) {
                    visit_island(grid, i, j, is_visited, m, n);
                    count++;
                }
            }
        }
        return count;
    }

    void visit_island(const Grid& grid, const int i, const int j, vector<vector<bool>>& is_visited, const int m, const int n) {
        if (i >=0 && j >= 0 && i < m && j < n && grid[i][j] == '1' && !is_visited[i][j]) {
            is_visited[i][j] = true;
            visit_island(grid, i - 1, j, is_visited, m, n);
            visit_island(grid, i + 1, j, is_visited, m, n);
            visit_island(grid, i, j - 1, is_visited, m, n);
            visit_island(grid, i, j + 1, is_visited, m, n);
        }
    }

};

int main() {
    return 0;
}
