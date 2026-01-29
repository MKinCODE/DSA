#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> need;
        for(string s: words2){
            unordered_map<char,int> temp;
            for(char ch : s ){ temp[ch]++; }
            for(auto it : temp){
                need[it.first]=max(need[it.first],it.second);     //max letter counts gets in the need map of whole word2 vector
            }
        } 
        vector<string> ans;
        for(string w : words1){
            unordered_map<char,int> freq;
            for(char ch : w){
                freq[ch]++;
            }
            bool ok = true;
            for(auto it : need){
                if(freq[it.first]<it.second){    //checks if string in words1 satisfy min req
                    ok=false;
                    break;
                }
            }
            if(ok){ans.push_back(w);}
        }
    return ans;
    }
};