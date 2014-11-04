#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

class Linkedlist
{
    public:
        Node *head;
        Linkedlist();
        ~Linkedlist();
        void insert(int data);
        void createCycle();
        void showList();
        void init(vector<int> &dataList);
    
    private:
        Node *tail; // Add for O(1) insertion
};
#endif
