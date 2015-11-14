// Given a value N, if we want to make change for N cents, and we have infinite supply of each of
// S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change?
// The order of coins doesn’t matter.

#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    using Matrix = vector<vector<int>>;
    int exchangeWays(int n, const vector<int> coins) {
        if (n < 1) return 0;
        Matrix dp(n + 1, vector<int>(coins.size() + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= coins.size(); ++j) {
                if (i > coins[j - 1]) {
                    dp[i][j] = dp[i - coins[j - 1]][j] + dp[i][j-1];
                } else if (i == coins[j - 1]) {
                    dp[i][j] = dp[i][j-1] + 1;
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp.back().back();
    }
};

int main() {
    vector<int> coins = {2, 5, 3, 6};
    vector<int> test_data = {10};
    Solution s;
    for (auto data : test_data) {
        cout << s.exchangeWays(data, coins) << endl;
    }
    return 0;
}
