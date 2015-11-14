#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void PreIn2Post(string pre, string in) {
        TreeNode* root = buildTree(pre, in);
        postOrderTraverse(root);
    }

    void postOrderTraverse(TreeNode* root) {
        if (root == nullptr) return;
        postOrderTraverse(root->left);
        postOrderTraverse(root->right);
        cout << root->val;
    }

    TreeNode* buildTree(string& preorder, string& inorder) {
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

    int treeBuilder(const string& preorder, const string& inorder, int in_start, int in_end, int pre, TreeNode*& node) {
        if (pre >= preorder.size() || pre < 0) return -1;
        int in = find_index(inorder, preorder[pre], in_start, in_end);
        if (in >= inorder.size() || in < 0) return pre;
        node = new TreeNode(inorder[in]);
        ++pre;
        pre = treeBuilder(preorder, inorder, in_start, in, pre, node->left);
        pre = treeBuilder(preorder, inorder, in + 1, in_end, pre, node->right);
        return pre;
    }

    int find_index(const string& data, char target, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (target == data[i]) {
                return i;
            }
        }
        return -1;
    }


};


int main(void) {
    string pre = "32451";
    string in = "42531";
    Solution().PreIn2Post(pre, in);
    cout << endl;
    return 0;
}
