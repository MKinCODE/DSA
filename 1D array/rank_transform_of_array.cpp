#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        int n=arr.size();
        vector<int> ans(n);
        for(int x:arr){
            mp[x];
        }
        int rank=1;
        for(auto &p:mp){
            p.second=rank++;
        }
        for(int i=0; i<n; i++){
            ans[i]=mp[arr[i]];
        }
        
        return ans;
    }
};