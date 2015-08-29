// https://leetcode.com/problems/reverse-linked-list-ii/
// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        unique_ptr<ListNode> pre_head(new ListNode(0));
        pre_head->next = head;
        ListNode* prior = pre_head.get();
        for (int i = 1; i < m; ++i) {
            prior = prior->next;
        }
        ListNode* end = prior->next;
        for (int i = m; i < n; ++i) {
            ListNode* next = end->next;
            end->next = next->next;
            next->next = prior->next;
            prior->next = next;
        }
        return pre_head->next;
    }
};

ListNode* create_list(const vector<int>& nums) {
    ListNode* head = new ListNode(0);
    ListNode* node = head;
    for (auto num : nums) {
        ListNode* current = new ListNode(num);
        node->next = current;
        node = node->next;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void print_node(ListNode* head) {
    ListNode* node = head;
    while (node != nullptr) {
        cout << node->val << ", ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> data1 = {3, 5, 7, 9, 11, 19, 22, 34};
    ListNode* data1_node = create_list(data1);
    ListNode* node = s.reverseBetween(data1_node, 1, 8);
    print_node(node);

    return 0;
}
