//



#include <iostream>
#include <list>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return root;
        if (p == nullptr) return q;
        if (q == nullptr) return p;
        list<TreeNode*> p_list;
        list<TreeNode*> q_list;
        // construct the p list
        find_list(root, p, p_list);
        find_list(root, q, q_list);
        auto pit = p_list.cbegin();
        auto qit = q_list.cbegin();
        while (pit != p_list.cend() && qit != q_list.cend() && (*pit)->val == (*qit)->val) {
            pit++;
            qit++;
        }
        cout <<  p_list.size() << endl;
        cout <<  q_list.size() << endl;
        if (pit == p_list.cend()) {
            return *(--pit);
        } else {
            return *(--qit);
        }
    }

    void find_list(TreeNode* from, TreeNode* target, list<TreeNode*>& l) {
        l.push_back(from);
        while (from->val != target->val) {
            if (from->val > target->val) {
                from = from->left;
            } else if (from->val < target->val) {
                from = from->right;
            }
            l.push_back(from);
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    Solution s;
    TreeNode* a = s.lowestCommonAncestor(root, root, root->left);
    cout << a->val << endl;
    return 0;
}
