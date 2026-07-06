#include<bits/stdc++.h>
using namespace std;

//more optimal acc to space
class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(char a:num){
            while(!st.empty() && st.back()>a && k>0){
                st.pop_back();
                k--;
            }
            st.push_back(a);
        }
        while(k>0){
            st.pop_back();
            k--;
        }
        if(st.empty()) return "0";

        int pos = st.find_first_not_of('0');   //find first character that is not '0'


        if(pos == string::npos)     //if pos is the end of string return 0
            return "0";

        st = st.substr(pos);      //cut string from there

        return st;
    }
};

//stack sol
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char a:num){
            while(!st.empty() && st.top()>a && k>0){
                st.pop();
                k--;
            }
            st.push(a);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int pos = ans.find_first_not_of('0');   //find first character that is not '0'


        if(pos == string::npos)     //if pos is the end of string return 0
            return "0";

        ans = ans.substr(pos);      //cut string from there

        return ans;
    }
};