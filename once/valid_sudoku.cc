
#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>


using namespace std;

class Solution {
public:
    using Board = vector<vector<char>>;
    bool isValidSudoku(vector<string>& board) {
        unordered_set<int> temp;
        vector<unordered_set<int>> o_vect(9, temp);
        vector<unordered_set<int>> p_vect(9, temp);
        vector<unordered_set<int>> q_vect(9, temp);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int x = static_cast<int>(board[i][j] - '0');
                    if (o_vect[i].find(x) != o_vect[i].end()) {
                        cout << "a" << endl;
                        return false;
                    }
                    if (p_vect[j].find(x) != p_vect[j].end()) {
                        cout << "b" << endl;
                        return false;

                    }
                    if (q_vect[i / 3 * 3 + j / 3].find(x) != q_vect[i / 3 * 3 + j / 3].end()) {
                        cout << i / 3 + j / 3 << endl;
                        cout << x << endl;
                        return false;
                    }
                    o_vect[i].insert(x);
                    p_vect[j].insert(x);
                    q_vect[i / 3 + j / 3].insert(x);
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<string>  test_data= {
        ".87654321","2........","3........",
        "4........","5........","6........",
        "7........","8........","9........"
    };

    cout << s.isValidSudoku(test_data) << endl;
    return 0;
}
