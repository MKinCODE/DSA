1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4        int x=0;
5        int y=0;
6        for(char ch:s){
7            if(ch=='(') x++;
8            else{
9                if(x>0) x--;
10                else y++;
11            }
12        }
13        return x+y;
14    }
15};