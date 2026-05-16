#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//better approach by using container internal  a vector
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int,vector<int>> st; //default internal container is dequeue but using vector is more efficient in terms of runtime
        int n=temperatures.size();
        vector<int> answer(n,0);
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                answer[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
       return answer;
    }
};

//my first thought
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n=temperatures.size();
        vector<int> answer(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i]>st.top().first){
                answer[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i],i});
        }
       return answer;
    }
};// later optimised with single stack

//brute force:
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(temperatures[j] > temperatures[i]) {
                    answer[i] = j - i;
                    break;
                }
            }
        }

        return answer;
    }
};