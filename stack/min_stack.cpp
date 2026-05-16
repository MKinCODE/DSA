#include<iostream>
#include<stack>
using namespace std;
//using two individual stacks
class MinStack {
public:
    stack<int> st;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            min.push(val);
        }
        else{
            if(val<=min.top()){
                min.push(val);
            }
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top()==min.top()){
            min.pop();
        }
        st.pop();

    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
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


 //using pair of stack
 class MinStack {
    stack<pair<int,int>> st; // {value, currentMin}
public:
    MinStack() {}

    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};