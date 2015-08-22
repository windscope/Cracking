/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {
        // corner case check, return nullptr if given nullptr
        if (node == nullptr) {
            return nullptr;
        }
        // initialize the root node and the node_map for storage and duplicate checking.
        // Node_map using the label as key since it is garuanteed that the label is unique
        UndirectedGraphNode* node_copy = new UndirectedGraphNode(node->label);
        unordered_map<int, UndirectedGraphNode*> node_map;
        // initialize the node_map
        node_map[node->label] = node_copy;
        // traverse
        dfs_traverse(node, node_copy, &node_map);
        return node_copy;
    }

    void dfs_traverse(
            const UndirectedGraphNode* node,
            UndirectedGraphNode* node_copy,
            unordered_map<int, UndirectedGraphNode*>* node_map) {
        if (node != nullptr) {
            for (auto neighbor: node->neighbors) {
                // If didn't in the node map, return true
                if (node_map->find(neighbor->label) == node_map->end()) {
                    UndirectedGraphNode* neighbor_copy = new UndirectedGraphNode(neighbor->label);
                    (*node_map)[neighbor_copy->label] = neighbor_copy;
                    node_copy->neighbors.push_back(neighbor_copy);
                    dfs_traverse(neighbor, neighbor_copy, node_map);
                } else {
                    // If the neighbor found in the map, insert the stored one
                    node_copy->neighbors.push_back((*node_map)[neighbor->label]);
                }
            }
        }
    }
};

int main() {
    Solution s;
    UndirectedGraphNode* node  = new UndirectedGraphNode(1);
    node->neighbors.push_back(node);
    node->neighbors.push_back(node);
    UndirectedGraphNode* node_copy = s.cloneGraph(node);
    assert(node_copy->label == node->label);
    cout << "You Passed!" << endl;
    return 0;
}
