#include<iostream>
#include<cstring>
using namespace std; 
class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int j=0;j<s.length();j++){
            if(s==goal){return true;}
            else{char temp = s[0];
                for(int i=0;i<s.length();i++){
                     s[i]=s[i+1];
            }
            s[(s.length())-1]=temp;
            }

        }
        return false;
    }
};