#include <iostream>
#include <vector>
#include <set>
#include "Linkedlist.h"
#include <assert.h>

using namespace std;

class Solution{
    public:
        static Node *return_head_race(Linkedlist &list)
        {// Using racing iterator to solve linkedlist question. 
            Node *slowIt, *quickIt;
            slowIt = quickIt = list.head;
            do
            {
                slowIt = slowIt->next;//the slow iterator step 1 node a time
                quickIt = quickIt->next->next;// the quick iterator step 2 node a time
            }
            while(slowIt != quickIt);
            return slowIt;

        }
        static Node *return_head_has(Linkedlist &list)
        {
            Node *it = list.head;
            set<Node *> lookupDict;
            while(lookupDict.find(it) == lookupDict.end())
            {
                lookupDict.insert(it);
                it = it->next;
            }
            return it;
        }
};



int main(void)
{
    Linkedlist list;
    vector<int> test={1,2,3,4,5,6,7,8,9};
    list.init(test);
    list.createCycle();
    Node *result1 = Solution::return_head_race(list);
    Node *result2 = Solution::return_head_has(list);
    assert(result1==list.head);
    assert(result2==list.head);
    cout<<"You win!"<<endl;
    cout<<"Two racing iterator give us the Node["<<result1->data<<"]\n";
    cout<<"Hashtable method give us the Node["<<result2->data<<"]\n";
    list.breakCycle();
    return 0;
}
