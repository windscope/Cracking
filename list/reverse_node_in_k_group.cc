#include <vector>
#include <memory>
#include <iostream>

using namespace std;
// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        unique_ptr<ListNode> pre_head(new ListNode(0));
        pre_head->next = head;
        ListNode* pre = pre_head.get();
        while (head != nullptr) {
            ListNode* tail = head;
            int i = 0;
            for (; i < k - 1 && tail != nullptr; ++i) {
                tail = tail->next;
            }
            if (tail != nullptr && i == k - 1) {
                reverseList(head, tail);
                pre->next = tail;
                pre = head;
            }
            head = head->next;

        }
        return pre_head->next;
    }

    void reverseList(ListNode* head, ListNode* tail) {
        unique_ptr<ListNode> pre_head(new ListNode(0));
        ListNode* pre = pre_head.get();
        pre->next = head;
        ListNode* cur = head;
        while (pre->next != tail) {
            ListNode* next = cur->next;
            cur->next = next->next;
            if (pre->next != head) {
                next->next = pre->next;
            } else {
                next->next = cur;
            }
            pre->next = next;
        }
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
    vector<int> data1 = {1,2, 3,4, 5, 6, 7};
    ListNode* data1_node = create_list(data1);
    print_node(data1_node);
    // ListNode* node = s.reverseList(data1_node, data1_node->next->next->next);
    // print_node(node);
    ListNode* node = s.reverseKGroup(data1_node, 0);
    print_node(node);

    return 0;
}
