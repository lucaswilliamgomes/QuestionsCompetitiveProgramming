#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    vector<int> minStack;
    vector<int> minCurrent;
    MinStack() {
        
    }
    
    void push(int val) {
        minStack.push_back(val);
        if (minCurrent.size()) {
            if (val < minCurrent[minCurrent.size() - 1]) 
                minCurrent.push_back(val);
            else
                minCurrent.push_back(minCurrent[minCurrent.size() - 1]);
        } else {
            minCurrent.push_back(val);
        }
    }
    
    void pop() {
        minCurrent.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        if (minStack.size()) 
            return minStack[minStack.size() - 1];
    }
    
    int getMin() {
        if (minCurrent.size()) return minCurrent[minCurrent.size() -1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char const *argv[])
{
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl; // return -3
    minStack->pop();
    cout << minStack->top() << endl;    // return 0
    cout << minStack->getMin() << endl; // return -2
    
    return 0;
}
