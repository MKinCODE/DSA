#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st;
        string result="";
        while(getline(ss,token,'/')){
            if(token=="" || token==".") continue;
            else if(token==".."){
                if(!st.empty()) st.pop_back();
            }
            else st.push_back(token);
        }
        for(auto x:st){
            result+="/"+x;
        }
        return result.empty() ? "/":result;
    }
};