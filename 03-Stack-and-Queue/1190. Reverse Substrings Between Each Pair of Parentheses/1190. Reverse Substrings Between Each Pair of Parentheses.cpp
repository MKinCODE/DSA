1class Solution {
2public:
3    string reverseParentheses(string s) {
4        stack<char> st;
5        for(int x=0; x<s.length(); x++){
6            if(s[x]==')'){
7                string curr = ;
8                while(st.top()!='('){
9                    curr+=st.top();
10                    st.pop();
11                }
12                st.pop();
13                for(int j=0; j<curr.length(); j++){
14                    st.push(curr[j]);
15                }
16            }
17            else st.push(s[x]);
18        }
19        string ans=;
20        while(!st.empty()){
21            ans = st.top() + ans;
22            st.pop();
23        }
24        return ans;
25    }
26};