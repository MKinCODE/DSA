#include<bits/stdc++.h>
using namespace std;

//assume a matrix of sum of the two arrays and treat like merge k lists q
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        
        for(int i=0;i<min((int)nums1.size(),k);i++){
            pq.push({nums1[i]+nums2[0],i,0});
        }

        vector<vector<int>> ans;
        while(k--){
            auto [sum,i,j] = pq.top();
            ans.push_back({nums1[i],nums2[j]});
            pq.pop();
            if(j+1<nums2.size()){
                pq.push({nums1[i]+nums2[j+1],i,j+1});

            }
        }

        return ans;
    }
};