#include<iostream>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        map<int,int> lar;
        for(int x: nums){
            lar[x]++;
        }
        for(auto it= lar.rbegin(); it!=lar.rend();++it){
            if(it->second==1){return it->first;}
        }
        return -1;
    }
};

//unordered approach
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxi = INT_MIN;
        for(int x: nums){
            freq[x]++;
            if(freq[x]>1){freq.erase(x);}
        }
        if(freq.empty()){return -1;}
        for(auto it : freq){
            maxi=max(maxi,it.first);
        }
        return maxi;
    }
};