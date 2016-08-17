#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {

public:
    string alienOrder(vector<string>& words) {
        if (words.size() < 1) {
            return {};
        }
        if (words.size() == 1) {
            return words.front();
        }
        unordered_map<char, unordered_set<char>> graph;
        for (size_t i = 1; i < words.size(); ++i) {
            auto& prev = words[i-1];
            auto& cur = words[i];
            bool changed = false;
            for (size_t j = 0; j < cur.size() || j < prev.size(); ++j) {
                if (j < prev.size() && graph.count(prev[j]) < 1) {
                    graph[prev[j]] = {};
                }
                if (j < cur.size() && graph.count(cur[j]) < 1) {
                    graph[cur[j]] = {};
                }
                if (!changed && j < cur.size() && j < prev.size() && cur[j] != prev[j]) {
                    graph[prev[j]].insert(cur[j]);
                    changed = true;
                }
            }
        }
        vector<char> cycle(26, false);
        vector<char> visit(cycle);
        string ret{};
        function<bool(const char)> dfs = [&dfs, &ret, &cycle, &visit, &graph] (const char c) {
            int key = c - 'a';
            if (cycle[key]) {
                return false;
            }
            if (visit[key]) {
                return true;
            }
            cycle[key] = true;
            for (const auto nc : graph[c]) {
                if (!dfs(nc)) {
                    return false;
                }
            }
            ret.push_back(c);
            visit[key] = true;
            cycle[key] = false;
            return true;
        };
        for (const auto& p : graph) {
            if (!dfs(p.first)) {
                return {};
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(void) {
    vector<vector<string>> data = {
        {"wrt","wrf","er","ett","rftt"},
        {"wnlb"},
        {},
        {"a", "b", "a"},
        {"fzhwdxo","lg","gu","ntndzbhnud","wiehfmh","itetkyeqwq","rp","wrbx","upjx","quhnr","kf","onv","ycjlkl","te","mtvzh","b","bk","q","lqme","iaprvi"}
    };
    Solution s;
    for (auto& d : data) {
        cout << s.alienOrder(d) << endl;
    }
    return 0;
}
