#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        // build the graph
        if (words.size() == 1) {
            return words.front();
        }
        unordered_map<char, unordered_set<char>> graph;
        for (int i = 1; i < words.size(); ++i) {
            const string& t1 = words[i - 1];
            const string& t2 = words[i];
            bool changed = false;
            for (int i = 0; i < t1.size() || i < t2.size(); ++i) {
                if (i < t1.size() && graph.count(t1[i]) < 1) {
                    graph.insert({t1[i], {}});
                }
                if (i < t2.size() && graph.count(t2[i]) < 1) {
                    graph.insert({t2[i], {}});
                }
                if (!changed && t1[i] != t2[i]) {
                    changed = true;
                    graph[t1[i]].insert(t2[i]);
                }
            }
        }
        return top_sort(graph);
    }
private:
    string top_sort(unordered_map<char, unordered_set<char>>& graph) {
        unordered_set<char> visited_nodes;
        unordered_set<char> cycle_detector;
        string ret;
        for (auto& node_pair : graph) {
            cout << node_pair.first << endl;
            if (!dfs(graph, visited_nodes, cycle_detector, node_pair.first, ret)) {
                return "";
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    bool dfs(unordered_map<char, unordered_set<char>>& graph,
            unordered_set<char>& visited_nodes,
            unordered_set<char>& cycle_detector,
            const char node,
            string& sorted_nodes) {
        if (cycle_detector.count(node) > 0) {
            return false;
        }
        if (visited_nodes.count(node) > 0) {
            return true;
        }
        cycle_detector.insert(node);
        visited_nodes.insert(node);

        for (auto it = graph[node].begin(); it != graph[node].end(); ++it) {
            if (!dfs(graph, visited_nodes, cycle_detector, *it, sorted_nodes)) {
                return false;
            }
        }
        cycle_detector.erase(node);
        sorted_nodes.push_back(node);
        return true;
    }


};


int main(void) {
    vector<string> data = {"wnlb"};
    Solution s;
    cout << s.alienOrder(data) << endl;
    return 0;
}
