// Word Search My Submissions Question Solution
// Total Accepted: 50012 Total Submissions: 239879 Difficulty: Medium
// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    using Board = vector<string>;
    bool exist(Board& board, string word) {
        if (board.empty()) return false;
        if (word.empty()) return true;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (check(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool traverse(Board& board, const string& word, int w, int i, int j) {
        if (w >= word.size()) return true;
        return (check(board, word, w, i + 1, j)
                || check(board, word, w, i, j + 1)
                || check(board, word, w, i - 1, j)
                || check(board, word, w, i, j - 1));
    }

    bool check(Board& board, const string& word, int w, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) return false;
        if (board[i][j] == word[w]) {
            char cache = board[i][j];
            board[i][j] = '\0';
            if(traverse(board, word, w + 1, i, j)) {
                return true;
            } else {
                board[i][j] = cache;
                return false;
            }
        }
    }
};

int main() {
    Solution::Board test_data = {"ABCE","SFCS","ADEE"};
    string test_data2 = "ABCB";
    Solution s;
    assert(!s.exist(test_data, test_data2));
    cout << "You Passed" << endl;
}



















