#include<bits/stdc++.h>
using namespace std;


class MyQueue {
public:
    stack<int> sin;   //used for input
    stack<int> sout;        //used for output
    MyQueue() {
        
    }
    
    void push(int x) {
        sin.push(x);
    }
    
    int pop() {
        if(sout.empty()){
            if(sin.empty()) return -1;
            while(!sin.empty()){
                sout.push(sin.top());
                sin.pop();
            }
        }
        int ans=sout.top();
        sout.pop();

        return ans;
    }
    
    int peek() {
        if(sout.empty()){
            if(sin.empty()) return -1;
            while(!sin.empty()){
                sout.push(sin.top());
                sin.pop();
            }
        }
        int ans=sout.top();

        return ans;
    }
    
    bool empty() {
        return sin.empty() && sout.empty();
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