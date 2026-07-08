#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for (char x : s) {
            if (isalnum(x)) { // Checks if it's a letter or a number
                ans += tolower(x); // Converts to lowercase on the fly
            }
        }
        string rev=ans;
        reverse(ans.begin(),ans.end());
        if(rev==ans) return true;
        return false;
    }
};