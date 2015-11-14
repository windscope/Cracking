#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<int>> dp(s.size() + 1, vector<int>());
        dp[0].push_back(-1);
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (!dp[j].empty()) {
                    if (wordDict.find(s.substr(j, i - j + 1)) != wordDict.end()) {
                        dp[i + 1].push_back(j);
                    }
                }
            }
        }
        if (dp.back().empty()) {
            return {};
        } else {
            vector<vector<string>> storage;
            vector<string> starter;
            backtracking(s,dp, storage, starter, dp.size() - 1);
            vector<string> ret;
            stringstream ss;
            for (int i = 0; i < storage.size(); ++i) {
                for (auto it = storage[i].rbegin(); it != storage[i].rend(); ++it) {
                    ss << *it;
                    if (it != storage[i].rend() - 1) {
                        ss << " ";
                    }
                }
                ret.push_back(ss.str());
                ss.str(string());
                ss.clear();
            }
            return ret;
        }
    }

    void backtracking(const string& s, const vector<vector<int>>& dp, vector<vector<string>>& storage, vector<string>& starter, int index) {
        if (index == 0) {
            storage.push_back(starter);
            return;
        }
        for (auto item : dp[index]) {
            starter.push_back(s.substr(item, index - item));
            backtracking(s, dp, storage, starter, item);
            starter.pop_back();
        }
    }

};

int main() {
    Solution s;
    unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
    string data = "catsanddog";
    vector<string> results = s.wordBreak(data, dict);
    for (const auto& result : results) {
        cout << result << endl;
    }
}
