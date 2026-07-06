#include<iostream>
#include<vector>
#include<sstream>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        stack<string> st;
        string result="";
        while(getline(ss,token,'/')){
            if(token=="" || token==".") continue;
            else if(token==".."){
                if(!st.empty()) st.pop();
            }
            else st.push(token);
        }
        vector<string> temp;

        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        for (auto &dir : temp) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};