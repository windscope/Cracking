#include <iostream>
#include <vector>
#include <stack>
#include <assert.h>
#include "Linkedlist.h"
// Implement a function to check if a linked list is a palindrome. 
// A linkedlist is considered palindrome when we have: 1->2->3->0->5->0->3->2->1; 
using namespace std;

class Solution
{
    public:
        static bool isPalidrome(Linkedlist &list)
        {
            Node *fastIt, *slowIt;
            fastIt = slowIt = list.head;
            stack<int> lookupStack;
            while(fastIt != nullptr && fastIt->next != nullptr)
            {
                lookupStack.push(slowIt->data);
                fastIt = fastIt->next->next;
                slowIt = slowIt->next;
                
            }
            if(fastIt)// if the linkedlist's size is odd, skip the middle node
            {
                slowIt = slowIt->next;
            }
            while(slowIt!=nullptr && !lookupStack.empty() && slowIt->data==lookupStack.top())
            {
                slowIt = slowIt->next;
                lookupStack.pop();
            }
            if(slowIt==nullptr && lookupStack.empty())
                return true;
            else return false;
        }
};


int main(void)
{
    vector<int> test1 = {1,2,3,2,1};
    vector<int> test2 = {1,2,3,3,2,1};
    vector<int> test3 = {1,2,3,3,3,3,3,3,2,1,0};
    Linkedlist list1,list2,list3;
    list1.init(test1);
    list2.init(test2);
    list3.init(test3);
    assert(Solution::isPalidrome(list1));
    assert(Solution::isPalidrome(list2));
    assert(!Solution::isPalidrome(list3));
    cout<<"Pass"<<endl;
    return 0;
}
