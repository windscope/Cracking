#include <iostream>
#include <stack>
#include <assert.h>
#include <vector>

using namespace std;

class StackWithMin{
private:
    stack<int> minStack;
    stack<int> dataStack;
public:
    int top();
    void pop();
    void push(int value);
};

int StackWithMin::top(){
    if(dataStack.empty()){
        cout<<"Nothing is in the Stack"<<endl;
        return -1;
    }
    else{
        return dataStack.top();
    }
}

void StackWithMin::pop(){
    if(dataStack.empty()){
        cout<<"Nothing is in the stack"<<endl;
        return;
    }
    else{
        int temp = dataStack.top();
        dataStack.pop();
        assert(!minStack.empty());
        if(dataStack.top() != temp && minStack.top() != temp){
            minStack.pop();
        }
    }
}

void StackWithMin::push(int value){
    dataStack.push(value);
    if(dataStack.empty()){
        minStack.push(value);
    }
    else{
        if(value <minStack.top())
            minStack.push(value);
    }
}


int main(void){
    vector<int> testData1 = {1,2,3,4,5};
    vector<int> testData2 = {5,4,3,2,1};
    vector<int> testData3 = {5,5,5,5,5};
    StackWithMin testStack;
    for(unsigned int i = 0;i<testData1.size();i++){
        testStack.push(testData1[i]);
    }
    assert(testStack.top()==1);
    testStack.pop();
    assert(testStack.top() == 1);
    int count = 0;
    while(testStack.top() != -1){
        testStack.pop();
        count++;
    }
    assert(count == 3);
    for(unsigned int i = 0; i<5; i++){
        testStack.push(testData2[i]);
        testStack.push(testData3[i]);
    }
    testStack.push(1);
    assert(testStack.top()==1);
    testStack.pop();
    testStack.pop();
    assert(testStack.top()==1);
    cout<<"You pass!"<<endl;
    return 0;
    
}
