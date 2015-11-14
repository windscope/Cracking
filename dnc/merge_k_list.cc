// https://leetcode.com/problems/merge-k-sorted-lists/
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity

#include <queue>
#include <vector>
#include <iostream>
#include <cassert>
#include <memory>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

object Comparer {
    bool operator() (const ListNode* node1, const ListNode* node2) {
        return node1->val > node2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        priority_queue<ListNode*,vector<ListNode*>, Comparer> ordered_nodes;
        unique_ptr<ListNode> pre_head(new ListNode(0));
        ListNode* cur = pre_head.get();
        for (auto head : lists) {
            if (head != nullptr) {
                ordered_nodes.push(head);
            }
        }
        while (!ordered_nodes.empty()) {
            cur->next = ordered_nodes.top();
            cur = cur->next;
            ordered_nodes.pop();
            if (cur->next != nullptr) {
                ordered_nodes.push(cur->next);
            }
        }
        return pre_head->next;
    }
};

int main() {
    return 0;
}
