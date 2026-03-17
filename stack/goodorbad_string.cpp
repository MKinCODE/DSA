#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c:s){
            if (!st.empty() && is_bad_pair(st.top(),c)){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    };
    bool is_bad_pair(char c1, char c2){
        return tolower(c1)==tolower(c2) && c1!=c2;
    }
};