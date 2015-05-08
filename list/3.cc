#include<vector>
#include<iostream>
#include"Linkedlist.h"

using namespace std;

//Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
class Solution
{
    public:
        Linkedlist list;
        Node *step(int n)
        {
            Node *it = list.head;
            for(int count = 0; count<n; count ++)
            {
                if(it->next != nullptr)
                {
                    it = it->next;
                }
                else return it;
            }
            return it;
        }
        
        bool delete_in_middle(Node *middle)
        {
            if(middle == nullptr || middle->next == nullptr) return false;// if middle is a null ptr or middle is the tail ptr, return false since we cannot deal with it.
            else
            {
                Node *temp = middle->next;
                middle->data = temp->data;
                middle->next = temp->next;
                temp->next = nullptr;
                delete temp;
            }
        return true;
        }
};


int main(void){
    vector<int> test = {1,2,3,4,5};
    Solution s;
    s.list.init(test);
    s.list.showList();
    Node *temp = s.step(2);
    cout<<"Now temp is in Node["<<temp->data<<"]"<<endl;
    if(s.delete_in_middle(temp))
        s.list.showList();
    else cout<<"ERROR\n";
    temp = s.step(10);
    cout<<"Now temp is in Node["<<temp->data<<"]"<<endl;
    if(s.delete_in_middle(temp))
        s.list.showList();
    else cout<<"Error\n";
    return 0;
}
