// Binary Search Tree Iterator
// Implement an iterator over a binary search tree (BST).
// Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.
// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory,
// where h is the height of the tree.

#include <stack>
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

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur_node = root;
        update_node_stack();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !node_stack.empty() || (cur_node != nullptr);
    }

    /** @return the next smallest number */
    int next() {
        int ret = 0;
        if (cur_node != nullptr) {
            update_node_stack();
        }
        ret = update_current_node();
        cur_node = cur_node->right;
        return ret;
    }
private:
    void update_node_stack() {
        while (cur_node != nullptr) {
            node_stack.push(cur_node);
            cur_node = cur_node->left;
        }
    }
    int update_current_node() {
        cur_node = node_stack.top();
        node_stack.pop();
        return cur_node->val;
    }
    stack<TreeNode*> node_stack;
    TreeNode* cur_node;
};

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

    BSTIterator it = BSTIterator(root.get());
    while (it.hasNext()) cout << it.next() << ", ";
    cout << endl;

    return 0;
}
