#include <vector>
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
    ListNode* shift(ListNode* head, int& k) {
        ListNode* tail = head;
        int i = 0;
        for (; i < k && tail != nullptr; ++i) {
            tail = tail->next;
        }
        k = i;
        return tail;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        ListNode* pre = head;
        int nk = k;
        ListNode* tail = shift(head, nk);
        if (tail == nullptr) {
            k = k % nk;
            tail = shift(head, k);
        }
        while (tail->next != nullptr) {
            tail = tail->next;
            pre = pre->next;
        }
        tail->next = head;
        head = pre->next;
        pre->next = nullptr;
        return head;
    }
};


int main() {
    return 0;
}
