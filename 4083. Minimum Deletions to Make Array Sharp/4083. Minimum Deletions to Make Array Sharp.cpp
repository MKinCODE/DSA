1class Solution {
2public:
3    int minDeletions(vector<int>& nums) {
4        int count=0;
5        stack<int> st;
6        for(int x:nums){
7            if(!st.empty()){
8                if((st.top()^x)==0) {count++; continue;}
9            }
10            st.push(x);
11        }
12        return count;
13    }
14};