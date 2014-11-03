#include <iostream>
#include <vector>
#include "Linkedlist.h"
// Given a linkedlist, output a fix number of linkedlist with the fabonacci index
using namespace std;

class Solution
{
    public:
    static void fibonacci(Linkedlist &list, int num)
    {
        int accPrev, acc, countL, countF;// acc1 is the pre-accumulator, acc2 is the accumulator, count is for the linkedlist, count2 is for fabonacci
        accPrev = countL = 1;//initialize the linkedlist count and pre-accumulator to 1
        countF = acc = 0;
        Node *it = list.head;
        while(countF <num){
            countF ++;//count for the number of fabonacci
            int temp = accPrev;
            accPrev = acc+temp;
            acc = temp;
            while(countL != acc)
            {
                if(it != nullptr)
                {
                    it = it->next;
                    countL ++;
                }
                else
                {
                    cout<<"Out of range"<<endl;
                    return;
                }
            }
            cout<<it->data<<endl;
        }
    }
};


int main(void)
{
    vector<int> test1(10000);
    Linkedlist list;
    for(int i = 1; i<=10000; ++i)
    {
        test1[i-1] = i;
    }
    list.init(test1);
    list.showList();
    Solution::fibonacci(list,100);
}
