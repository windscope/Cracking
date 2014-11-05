#include <iostream>
#include <vector>
#include <unordered_map>
#include "Linkedlist"

using namespace std;

class Solution{

    static Node *return_head_race(Linkedlist &list)
    {// Using racing iterator to solve linkedlist question. 
        Node *slowIt, *quickIt;
        slowIt = quickIt = list.head;
        do
        {
            slowIt = slowIt->next;//the slow iterator step 1 node a time
            quickIt = quiclIt->next->next;// the quick iterator step 2 node a time
        }
        while(slowIt != quickIt);

    }
    static Node *return_head_has(Linkedlist &list)
    {

    }
};
