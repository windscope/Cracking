#include <iostream>
#include "Linkedlist.h"
#include<vector>
using namespace std;

Linkedlist::Linkedlist()
{
    this->head = nullptr;
}

Linkedlist::~Linkedlist()
{
    Node* current = head;
    while(current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = head;
    cout<<"We now delete the linkedlist"<<endl;
}

void Linkedlist::insert(int data)
{
    if(head == nullptr)
    {
        head =  new Node;
        head->data = data;
        head->next = nullptr;
        tail = head;
    } 
    else
    {
        tail->next = new Node;
        tail = tail->next;
        tail->data = data;
        tail->next = nullptr;
    }
}

void Linkedlist::createCycle()
{
    tail->next = head;
}

void Linkedlist::showList()
{
    Node *dispNode = head;
    int count = 0;
    while(dispNode->next != nullptr)
    {
        count ++;
        cout<<"Node["<<dispNode->data<<"]";
        if(count%12 != 0) cout<<"->";
        else cout<<endl<<"->";
        dispNode = dispNode->next;
    }
    cout <<"endNode[" << dispNode->data <<"]"<< endl;
}

void Linkedlist::init(vector<int> &dataList)
{
    for(int i = 0; i<dataList.size();++i)
    {
       insert(dataList[i]); 
    }
}
/* Add for testing
int main(void)
{
    Linkedlist try_list;
    vector<int> dataList;
    for(int i = 0;i < 11;i++)
    {
        dataList.push_back(i*2);
    }
    try_list.init(dataList);
    try_list.showList();
    return 0;
}
*/
