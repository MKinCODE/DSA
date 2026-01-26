#include<iostream>
#include<unordered_set>
#include<cstring>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){return 0;}
        unordered_set<char> us;
        int left=0;
        int ans=0;
        for(int right=0; right<s.length(); right++){
           
            if(us.find(s[right])!=us.end()){
                while(s[left]!=s[right]){us.erase(s[left]);
                left++;
                }
                us.erase(s[left]);
                left++;
                
                us.insert(s[right]);
            }
            else{ us.insert(s[right]);}
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};