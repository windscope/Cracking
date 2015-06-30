// Sourece https://leetcode.com/problems/add-two-numbers/

// You are given two linked lists representing two non-negative numbers. The digits are stored in
// reverse order and each of their nodes contain a single digit. Add the two numbers and return
// it as a linked list.

// Score: 40 ms
// Lession learnt: too simple

// Alogrithm:
//     first get a combinition

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    const static int TEN = 10;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNodes(l1, l2, 0);
    }

    ListNode* addTwoNodes(const ListNode* l1, const ListNode* l2, const int carry) {
        int sum = carry;
        ListNode* l1_next = nullptr;
        ListNode* l2_next = nullptr;
        if (l1 != nullptr) {
            sum += l1.val;
            l1_next = l1.next;
        }
        if (l2 != nullptr) {
            sum += l2.val;
            l2_next = l2.next;
        }
        if (l1 == l2 && l1 == nullptr && sum == 0) {
            return nullptr;
        } else {
            int carry_next = sum/TEN;
            sum %= TEN;
            ListNode* l3 = new ListNode(sum);
            l3->next = addTwoNodes(l1_next, l2_next, carry_next);
            return l3;
        }
    }
};

