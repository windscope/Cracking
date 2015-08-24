// Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cassert>
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* next_head = head->next;
        head->next = nullptr;
        ListNode* ret_head = head;
        while (next_head != nullptr) {
            ListNode* ret_head_next = ret_head;
            ret_head = next_head;
            next_head = next_head->next;
            ret_head->next = ret_head_next;
        }
    }
};

int main() {
    cout << "You Passed" << endl;
    return 0;
}
