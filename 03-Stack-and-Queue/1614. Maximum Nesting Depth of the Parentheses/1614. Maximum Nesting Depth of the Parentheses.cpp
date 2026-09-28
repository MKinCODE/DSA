1class Solution {
2public:
3    int maxDepth(string s) {
4        int ans = INT_MIN;
5        stack<char> st;
6        for(char ch:s){
7            if(ch=='(') st.push(ch);
8            else if(ch==')'){
9                int size=st.size();
10                ans=max(ans,size);
11                st.pop();
12            }
13        }
14        return ans==INT_MIN? 0:ans;
15    }
16};