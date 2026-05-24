#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int passwordStrength(string password) {
        int strength=0;
        unordered_set<char> us;
        int n=password.length();
        for(int i=0;i<n;i++){
            if(password[i]>='a' && password[i]<='z' && us.find(password[i])==us.end()) {
                strength++; 
                us.insert(password[i]);
            }
            else if(password[i]>='A' && password[i]<='Z' && us.find(password[i])==us.end()) {
                strength=strength+2; 
                us.insert(password[i]);
            }
            else if(password[i]>='0' && password[i]<='9' && us.find(password[i])==us.end()) {
                strength=strength+3; 
                us.insert(password[i]);
            }
            else if((password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$') && us.find(password[i])==us.end()){
                strength=strength+5; 
                us.insert(password[i]);
            }
        }
        return strength;
    }
};