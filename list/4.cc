/*
*You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
Output: 8 -> 0 -> 8
*/
#include <iostream>
#include <vector>
#include "Linkedlist.h"
#include <cmath>
using namespace std;

class Solution
{
    public:
        static void sumList(Linkedlist &list1,Linkedlist &list2)
        {// To lazy to overwrite an assignment operator=,so I will print out the linked list 
            if(list1.head ==nullptr &&list2.head == nullptr) 
            {
                cout<<"Error"<<endl;
                return;
            }
            int data[2],count[2],overflow,sum;
            Node *it[2];
            it[0] = list1.head;
            it[1] = list2.head;
            Linkedlist resultList;
            data[0]=data[1]=count[0]=count[1]=overflow=sum=0;
            while(it[0] != nullptr || it[1] != nullptr)
            {
                 if(it[0] != nullptr)
                {
                    data[0] = it[0]->data;
                    it[0] = it[0]->next;
                    count[0] ++;
                }
                if(it[1] != nullptr)
                {   
                    data[1] = it[1]->data;
                    it[1] = it[1]->next;
                    count[1] ++;
                }

                if(count[0] == count[1])
                {
                    sum = data[0] + data[1] + overflow;
                }
                else
                {
                    int i = count[0]>count[1]? 0:1;
                    sum = data[i] + overflow;
                }
                if(sum>10) 
                {
                    overflow = 1;
                    sum = sum -10;
                }
                else overflow = 0;
                resultList.insert(sum);
                if(overflow&&count[0]==count[1]&&it[0]==nullptr&&it[1]== nullptr)//if list1 length == list2 length, and overflowed
                    resultList.insert(overflow);
             }
        resultList.showList();
        }
};


int main()
{
    vector<int> test1 = {5,5,5};
    vector<int> test2 = {4,4,4,2};
    vector<int> test3 = {6,9,7};
    Linkedlist list1,list2,list3;
    list1.init(test1);
    list2.init(test2);
    list3.init(test3);
    list1.showList();
    list3.showList();
    cout<<"Add these two list"<<endl;
    Solution::sumList(list1,list2);
    return 0;
}
