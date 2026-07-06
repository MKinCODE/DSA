#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> stc;
        stack<string> st;
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num=num*10 + (c-'0');
            }
            else if(c=='['){
                stc.push(num);
                num=0;
                st.push("[");
            }
            else if(c==']'){
                string a="";
                while(st.top()!="["){
                    a=st.top()+a;
                    st.pop();
                }
                st.pop();
                int k=stc.top();
                stc.pop();
                string b=a;
                for(int i=0;i<k-1;i++) a+=b;
                st.push(a);
            }
            else{st.push(string(1,c));} 
        }
        string result="";
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }
        return result;
    }
};