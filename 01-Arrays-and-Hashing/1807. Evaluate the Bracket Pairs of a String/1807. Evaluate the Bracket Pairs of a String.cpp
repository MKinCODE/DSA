1class Solution {
2public:
3    string evaluate(string s, vector<vector<string>>& knowledge) {
4        unordered_map<string,string> um;
5        for(int i=0; i<knowledge.size();i++){
6            um[knowledge[i][0]]=knowledge[i][1];
7        }
8        string ans=;
9        for(int i=0; i<s.length(); i++){
10            if(s[i]=='('){
11                string key = ;
12                i++;
13                while(s[i]!=')'){
14                    key+=s[i++];
15                }
16                if (um.find(key) == um.end()) ans+='?';
17                else ans+=um[key];
18            }
19            else ans+=s[i];
20        }
21        return ans;
22    }
23};