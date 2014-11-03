#include <unordered_map>
#include <vector>
#include <iostream>
#include "Linkedlist.h"
/*
2.1.1: Write code to remove duplicates from an unsorted linked list.
2.1.2: FollowUp: How would you solve this problem if a temporary buffer is not allowed?
*/
using namespace std;

class Solution
{
    public:
        // Solution 1, when extra buffer are allowed, using hashtable, time complexity is O(1);
        static void solution2_1_1(Linkedlist &list)
        {
            unordered_map<int,bool> lookupDict;
            Node *it = list.head;
            Node *itPrev = list.head;
            while(it != nullptr)
            {
                if(lookupDict.find(it->data) == lookupDict.end())
                {
                    lookupDict[it->data] = true;
                    itPrev = it;
                    it = it->next;
                }
                else
                {
                    itPrev->next  = it->next;
                    it->next = nullptr;
                    delete it;
                    it = itPrev->next;
                }
            }
        }
        // Solution 2 for the follow-up question. When no extra buffer is allowed, must use two iterator to loop through the list, O(n^2) time complexity. 
        static void solution2_1_2(Linkedlist &list)
        {
            Node *it = list.head;
            while(it!= nullptr)
            {
                Node *deletor_it = it->next;
                Node *deletor_itPrev = deletor_it;
                while(deletor_it != nullptr)
                {
                    if(deletor_it->data == it->data)
                    {
                        if(deletor_itPrev == deletor_it)// if deletor_it has not moved(it->next = deletor_it)
                        {
                            deletor_it = deletor_it->next;
                            it->next = deletor_it;
                            deletor_itPrev->next = nullptr;
                            delete deletor_itPrev;
                            deletor_itPrev = deletor_it;
                        }
                        else// deletor has moved
                        {
                            deletor_itPrev->next = deletor_it->next;
                            deletor_it->next = nullptr;
                            delete deletor_it;
                            deletor_it = deletor_itPrev->next;
                        }
                    }
                    else
                    {
                        if(deletor_itPrev == deletor_it)
                        {
                            deletor_it = deletor_it->next;
                        }
                        else
                        {
                            deletor_itPrev = deletor_it;
                            deletor_it = deletor_it->next;
                        }
                    }
                }
                it = it->next;
           
            }
        }
};


int main(void)
{
    vector<int> test1 = {1,2,3,4,1,2,3,4,1,2,3,4};
    vector<int> test2 = {1,1,1,1,1,1,1};
    vector<int> test3 = {1,2,1,2,2,2,3,3,4,2,1};
    Linkedlist *sample = new Linkedlist;
    cout<<"Solution 1 using hastable:"<<endl<<"Initialzing:";
    sample->init(test1);
    sample->init(test2);
    sample->init(test3);
    sample->showList();
    Solution::solution2_1_1(*sample);
    cout<<"After deleting: ";
    sample->showList();
    cout<<"Solution 2 with no buffer :"<<endl<<"Initialzing:";
    sample->init(test1);
    sample->init(test2);
    sample->init(test3);
    sample->showList();
    Solution::solution2_1_2(*sample);
    cout<<"After deleting: ";
    sample->showList();

    delete sample;
    return 0;
}
