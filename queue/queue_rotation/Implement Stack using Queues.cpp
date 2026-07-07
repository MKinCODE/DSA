#include<bits/stdc++.h>
using namespace std;


//more spcae optimal
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size=q.size()-1;
        while(size--){
            int a=q.front();
            q.pop();
            q.push(a);
        }
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        int size=q.size()-1;
        while(size--){
            int a=q.front();
            q.pop();
            q.push(a);
        }
        int ans=q.front();
        q.pop();
        q.push(ans);
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//less space optimal
class MyStack {
public:
    queue<int> qin;
    queue<int> qout;
    MyStack() {
        
    }
    
    void push(int x) {
        qin.push(x);
    }
    
    int pop() {
        while(qin.size()!=1){
            qout.push(qin.front());
            qin.pop();
        }
        int ans=qin.front();
        qin.pop();
        while(!qout.empty()){
            qin.push(qout.front());
            qout.pop();
        }
        return ans;
    }
    
    int top() {
        while(qin.size()!=1){
            qout.push(qin.front());
            qin.pop();
        }
        int ans=qin.front();
        qout.push(ans);
        qin.pop();
        while(!qout.empty()){
            qin.push(qout.front());
            qout.pop();
        }
        return ans;
    }
    
    bool empty() {
        return qin.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */