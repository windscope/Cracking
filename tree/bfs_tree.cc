// bfs traverse the tree

#include <stack>
#include <queue>
#include <iostream>
#include <memory>

using namespace std;


// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void visit(TreeNode* node) {
    cout << node->val << ", ";
}

void bfs_node_traverse(TreeNode* node) {
    queue<TreeNode*> node_queue;
    node_queue.push(node);
    TreeNode* cur_node = nullptr;
    while (!node_queue.empty()) {
        cur_node = node_queue.front();
        node_queue.pop();
        if (cur_node != nullptr) {
            node_queue.push(cur_node->left);
            node_queue.push(cur_node->right);
            visit(cur_node);
        }
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    unique_ptr<TreeNode> root(new TreeNode(5));
    root->left = new TreeNode(3);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);
    root->right->right = new TreeNode(10);
    // the result should be in the following order:
    // 5, 3, 9, 2, 4, 7, 10, 1 ,6, 8
    bfs_node_traverse(root.get());
    cout << endl;
    return 0;
}
