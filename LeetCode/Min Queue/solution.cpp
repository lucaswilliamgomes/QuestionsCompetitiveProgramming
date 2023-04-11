#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:

    stack<pair<int, int>> st1, st2;

    MyQueue() {
        
    }
    
    // Sempre dar push em {x, menor encontrado em st1}
    void push(int x) {
        if (st1.empty()) {
            st1.push({x, x});
        } else {
            st1.push({x, st1.top().second});
        }
    }

    
    int pop() {
        if (st2.empty()) {
            while(!st1.empty()) {
                auto p = st1.top();
                st1.pop();
                if (st2.empty()) {
                    st2.push({p.first, p.first});
                } else {
                    st2.push({p.first, min(p.first, st2.top().second)});
                }
            }
        }

        if (!st2.empty()) {
            int deleted = st2.top().first;
            st2.pop();
            return deleted;
        } else {
            throw "Empty queue";
        }
    }
    
    int peek() {
        if (st2.empty()) {
            while(!st1.empty()) {
                auto p = st1.top();
                st1.pop();
                if (st2.empty()) {
                    st2.push({p.first, p.first});
                } else {
                    st2.push({p.first, min(p.first, st2.top().second)});
                }
            }
        }

        if (!st2.empty()) {
            int top = st2.top().first;
            return top;
        } else {
            throw "Empty queue.";
        }
    }
    
    bool empty() {
        if (st2.empty() && st1.empty()) return true;
        else return false;
    }

    bool size() {
        return st1.size() + st2.size();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char const *argv[])
{

    MyQueue myQueue = MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek() << endl; // return 1
    cout << myQueue.pop() << endl; // return 1, queue is [2]
    cout << myQueue.empty() << endl; // return false
    return 0;
}
