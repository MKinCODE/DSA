1class Solution {
2public:
3    int longestValidParentheses(string s) {
4        stack<pair<char,int>> st;
5        int size = s.length();
6        for(int i=0; i<size;i++){
7            if(s[i]=='(') st.push({s[i],i});
8            else{
9                if(st.empty() || st.top().first!='(') st.push({')',i});
10                else{
11                    st.pop();
12                }
13            }
14        }
15        if(st.empty()) return size;
16
17        int prev = st.top().second;
18        int ans = abs(prev - size) - 1;
19
20        while(!st.empty()){
21            prev = st.top().second;
22            st.pop();
23            if(!st.empty())ans=max(ans,prev-st.top().second-1);
24        }
25        ans=max(ans,prev-0);
26        return ans;
27    }
28};