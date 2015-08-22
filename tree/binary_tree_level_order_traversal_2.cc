// Binary Tree Level Order Traversal II
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    typedef vector<vector<int>> two_d_vector_t;

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> even_queue, odd_queue;
        two_d_vector_t level_vec = {{}};
        even_queue.push(root);

        queue<TreeNode*>* cur_queue = &even_queue;
        queue<TreeNode*>* next_queue = &odd_queue;
        vector<int>* cur_vect = &level_vec[0];

        while(!(odd_queue.empty() && even_queue.empty())) {
            while (!cur_queue->empty()) {
                TreeNode* cur_node = cur_queue->front();
                cur_queue->pop();
                if (cur_node->left != nullptr) {
                    next_queue->push(cur_node->left);
                }
                if (cur_node->right != nullptr) {
                    next_queue->push(cur_node->right);
                }
                cur_vect->push_back(cur_node->val);
            }
            // switch the queue if needed
            if (!next_queue->empty()) {
                queue<TreeNode*>* temp_queue = cur_queue;
                cur_queue = next_queue;
                next_queue = temp_queue;
                level_vec.push_back({});
                cur_vect = &level_vec[level_vec.size() - 1];
            }

        }
        reverse(level_vec.begin(), level_vec.end());
        return level_vec;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    Solution::two_d_vector_t result = s.levelOrderBottom(root);
    for (auto vect : result) {
        for (auto item : vect) {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}
