#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;
class Solution{
private:
    priority_queue<int,vector<int>, greater<int>> preQue;
    stack<int> dataStack;
public:
    void populateStack(const vector<int> &dataVec){
        for(unsigned int i=0; i < dataVec.size(); ++i){
                dataStack.push(dataVec[i]);
            }
    }
    void sortStack(){
            while(!dataStack.empty()){
                preQue.push(dataStack.top());
                dataStack.pop();
            }
        }
    void printCleanPreQue(){
        while(!preQue.empty()){
                cout<<preQue.top()<<"<";
                preQue.pop();
            }
        cout<<endl;
    }
};

int main(){
    vector<int> dataList = {1,4,3,5,2,6,7,9,8,0};
    Solution solution;
    solution.populateStack(dataList);
    solution.sortStack();
    solution.printCleanPreQue();
    return EXIT_SUCCESS;
}
