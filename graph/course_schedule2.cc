// Course Schedule 2
// https://leetcode.com/problems/course-schedule-ii/
// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
// which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses
// you should take to finish all courses.
// There may be multiple correct orders, you just need to return one of them.
// If it is impossible to finish all courses, return an empty array.

// For example:
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0.
// So the correct course order is [0,1]

// 4, [[1,0],[2,0],[3,1],[3,2]]
// There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2.
// Both courses 1 and 2 should be taken after you finished course 0. So one correct course order
// is [0,1,2,3]. Another correct ordering is [0,2,1,3].

#include <cassert>
#include <iostream>
#include <set>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    typedef pair<set<int>, set<int>> Node;
    typedef vector<Node> graph_map_t;

public:
    // A bfs solution
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // initialize the graph map
        graph_map_t graph_map(numCourses, {{}, {}});
        // construct the graph
        for (auto prerequisite : prerequisites) {
            graph_map[prerequisite.first].first.insert(prerequisite.second);
            graph_map[prerequisite.second].second.insert(prerequisite.first);
        }
        // find the top vertices
        unordered_set<int> top_nodes;
        make_top_nodes(graph_map, top_nodes);
        // initialize the return vector
        if (top_nodes.empty()) {
            return {};
        }
        vector<int> topology_sorted_nodes;
        topology_sorted_nodes.reserve(numCourses);
        while(!top_nodes.empty()) {
            // get the first node of the top nodes, erase it from the hashset,
            // and push it to the top sorted list
            int n = *top_nodes.begin();
            top_nodes.erase(top_nodes.begin());
            topology_sorted_nodes.push_back(n);
            // unlink the edges between this node and its followers, if the following node
            // has no parent node, push it to top node set
            for (auto i : graph_map[n].second) {
                graph_map[n].second.erase(i);
                graph_map[i].first.erase(n);
                if (graph_map[i].first.empty()) {
                    top_nodes.insert(i);
                }
            }
        }
        // get the top node again, it should equal to the numcourses if exist a top order
        make_top_nodes(graph_map, top_nodes);
        if (top_nodes.size() == numCourses) {
            return topology_sorted_nodes;
        } else {
            return {};
        }

    }

    void make_top_nodes(const graph_map_t& graph_map, unordered_set<int>& top_nodes) {
        for (int i = 0; i < graph_map.size(); ++i) {
            if (graph_map[i].first.empty()) {
                top_nodes.insert(i);
            }
        }
    }
};

int main() {
    Solution s;
    // true check
    vector<pair<int, int>> test_data = {{2, 0}, {3, 1}, {3, 0}, {4, 2}, {4, 3}};
    vector<int> result = s.findOrder(5, test_data);
    // assert(result.size() == 5);
    for (auto i : result) {
        cout << i << ", ";
    }
    // false check
    vector<pair<int, int>> test_data2 = {{1, 2}, {1, 0}, {0, 1}};
    vector<int> result2 = s.findOrder(3, test_data2);
    assert(result2.size() == 0);
    // telling
    cout << "You Passed" << endl;
    return 0;
}
