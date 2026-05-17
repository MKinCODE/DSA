#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
//using flag
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(int num:asteroids){
            bool destroyed=false;
            while(!st.empty() && st.top()>0 && num<0){
                if(st.top()<-num){
                    st.pop();
                }
                else if(st.top()==-num){
                    destroyed=true;
                    st.pop();
                    break;
                }
                else{
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed) st.push(num);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//without using flag
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {

                while (!st.empty() && st.top() > 0 &&
                       st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop();
                }

                else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};