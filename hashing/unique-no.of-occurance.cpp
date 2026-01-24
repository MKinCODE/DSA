#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//less optimal in terms of time
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int x : arr) {
            freq[x]++;
        }
        for(auto it : freq){
            for(auto it2 : freq){
                if(it.second==it2.second && it!=it2){return false;}
            }
        }
    return true;
    }
};
//less optimal in terms of space
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        unordered_map<int,int> umap;
        for (int x : arr) {
            freq[x]++;
        }
        for(auto it : freq){
            umap[it.second]++;
        }
        for(auto it : umap){
            if(it.second>1){return false;}
        }
       return true; 
    }
};