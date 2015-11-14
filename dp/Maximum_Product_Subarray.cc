#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
        int max_producet = INT_MIN;
        int index = 0;
        while (index < nums.size() && nums[index] == 0) {
            ++index;
        }
        dp[0][index] = nums[index];
        dp[1][index] = nums[index];
        int ret = INT_MIN;
        int negIndex = -1;
        for (int i = index + 1; i < nums.size(); ++i) {
            // cout << "0: " << dp[0][i-1] << endl;
            // cout << "1: "<< dp[1][i-1] << endl;
            if (nums[i] > 0) {
                dp[1][i] = dp[1][i-1] * nums[i];
                dp[0][i] = dp[0][i-1] * nums[i];
            } else if (nums[i] == 0) {
                if (i + 1 < nums.size()) {
                    ++i;
                    dp[1][i] = nums[i];
                    dp[0][i] = nums[i];
                    negIndex = -1;
                }
            } else {
                if (negIndex == -1) {
                    negIndex = i;
                    dp[0][i] = dp[0][i-1] * nums[i];
                    ret = max(ret, dp[1][i-1]);
                    // cout << "max: " << ret << endl;
                    dp[1][i] = 1;
                } else {
                    if (dp[0][i-1] > 0) {
                        ret = max(ret, dp[1][i-1]);
                        dp[1][i] = dp[0][i-1] / dp[0][negIndex] * nums[i];
                    } else {
                        ret = max(ret, dp[1][i-1]);
                        dp[1][i] = dp[0][i-1] * nums[i];
                    }
                    dp[0][i] = dp[0][i-1] * nums[i];
                }
            }
        }
        return max(ret, dp[1].back());
    }
};

int main(void) {
    return 0;
}
