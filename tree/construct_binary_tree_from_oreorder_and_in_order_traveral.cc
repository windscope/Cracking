// Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Given preorder and inorder traversal of a tree, construct the binary tree.

#include <vector>
#include <iostream>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        int pre = 0;
        int in = find_index(inorder, preorder[pre], 0, inorder.size());
        if (in < 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pre]);
        pre = treeBuilder(preorder, inorder, 0, in, pre + 1, root->left);
        treeBuilder(preorder, inorder, in + 1, inorder.size(), pre, root->right);
        return root;
    }

    int treeBuilder(vector<int>& preorder, vector<int>& inorder, int in_start, int in_end, int pre, TreeNode*& node) {
        if (pre >= preorder.size() || pre < 0) return -1;
        int in = find_index(inorder, preorder[pre], in_start, in_end);
        if (in >= inorder.size() || in < 0) return pre;
        node = new TreeNode(inorder[in]);
        ++pre;
        pre = treeBuilder(preorder, inorder, in_start, in, pre, node->left);
        pre = treeBuilder(preorder, inorder, in + 1, in_end, pre, node->right);
        return pre;
    }

    int find_index(const vector<int>& data, int target, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (target == data[i]) {
                return i;
            }
        }
        return -1;
    }
};

void in_order(TreeNode* root) {
    if (root) {
        in_order(root->left);
        cout << root->val << endl;
        in_order(root->right);
    }
}
void pre_order(TreeNode* root) {
    if (root) {
        cout << root->val << endl;
        pre_order(root->left);
        pre_order(root->right);
    }
}
int main() {
    vector<int> data_in = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    vector<int> data_pre = {7, 5, 4, 2, 1, 3, 6, 10, 8, 9, 12, 11, 13};
    Solution s;
    TreeNode* root = s.buildTree(data_pre, data_in);
    cout << "inorder: " << endl;
    in_order(root);
    cout << "preorder: " << endl;
    pre_order(root);

}
