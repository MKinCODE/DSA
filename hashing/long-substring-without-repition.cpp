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
                while(s[left]!=s[right]){us.erase(s[left]);      //reach until we get which right char is equal to left pointing char
                left++;
                }
                us.erase(s[left]);                              //after we reach there we remove that left and ...
                left++;
                
                us.insert(s[right]);                            //...begin with new subarray
            }
            else{ us.insert(s[right]);}
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};