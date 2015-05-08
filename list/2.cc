//Implement an algorithm to find the nth to last element of a singly linked list.
#include <iostream>
#include <vector>
#include "Linkedlist.h"

using namespace std;

class Solution{
    public:    
    static void findLastN(Linkedlist &list, int n)
    {
        Node *it1;
        Node *it2;
        it1 = it2 = list.head;
        int count = 0;
        while(it1 != nullptr)
        {
            it1 = it1->next;
            if(count >= n)
            {
                it2 = it2->next;
            }
            count ++;
        }
        cout<<it2->data<<endl;
    }
};


int main(void)
{
    vector<int> test1(100);
    for(int i = 0;i<100;i++)
    {
        test1[i] = i+1;
    }
    Linkedlist list;
    list.init(test1);
    list.showList();
    Solution::findLastN(list,10);
}
