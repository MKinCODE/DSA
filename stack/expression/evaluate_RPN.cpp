#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string calculate(string a, string b, string op){
        int x = stoi(a);
        int y = stoi(b);

        if(op=="+") return to_string(x+y);
        if(op=="-") return to_string(x-y);
        if(op=="*") return to_string(x*y);
        return to_string(x/y);
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string c: tokens){
            if(c=="+" || c=="-" || c=="*" || c=="/"){
                string a = st.top();
                st.pop();

                string b = st.top();
                st.pop();

                st.push(calculate(b,a,c));
            }
            else{
                st.push(c);
            }
        }

        return stoi(st.top());
    }
};