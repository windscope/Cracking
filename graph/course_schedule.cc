// Course Schedule
// https://leetcode.com/problems/course-schedule/
// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0 you have to first take
// course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs,
// is it possible for you to finish all courses?

// For example:
// 2, [[1,0]]
// There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.

// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0,
// and to take course 0 you should also have finished course 1. So it is impossible.
// Algorithm: build graph + topology sesearch

#include <cassert>
#include <iostream>
#include <set>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// define the graph node
struct GraphNode {
    int val;
    set<GraphNode*> next_nodes;
    GraphNode(int x) : val(x) {};
};
// This algorithm is build the graph and then use dfs traverse to detect cycles
// This algorithm is actually not efficient: since I construct the graph not as a bi-diraction graph
// but a forest
// next time review rewrite this solution
class Solution {
public:
    bool canFinish(int numCourses, const vector<pair<int, int>>& prerequisites) {
        // node lookup map
        unordered_map<int, GraphNode*> node_map;
        for (int i = 0; i < numCourses; ++i) {
            node_map.insert(make_pair(i, new GraphNode(i)));
        }
        // build the graph
        for (auto prerequisite : prerequisites) {
            node_map[prerequisite.second]->next_nodes.insert(node_map[prerequisite.first]);
        }
        // from every node, try to find whether it is a cycle
        for (auto node : node_map) {
            unordered_set<GraphNode*> node_set;
            if (!isDAG(node.second, &node_set)) {
                return false;
            }
        }
        return true;
    }

    bool isDAG(GraphNode* node, unordered_set<GraphNode*>* node_set) {
        if (node_check_map.find(node->val) != node_check_map.end()) {
            return node_check_map[node->val];
        }
        if (node_set->find(node) == node_set->end()) {
            node_set->insert(node);
            for (auto next_node : node->next_nodes) {
                if(!isDAG(next_node, node_set)) {
                    node_check_map[node->val] = false;
                    return false;
                }
            }
        } else {
            // insert the found out value in node check map, to prevent duplicated check
            // aproximately dp solution
            node_check_map[node->val] = false;
            return false;
        }
        node_check_map[node->val] = true;
        return true;
    }
private:
    unordered_map<int, bool> node_check_map;
};

int main() {
    Solution s;
    vector<pair<int, int>> test_data = {{1, 0}, {0, 1}};
    assert(!s.canFinish(2, test_data));
    cout << "You Passed" << endl;
    return 0;
}
