#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();

        deque<int> dq;
        int ans=INT_MAX;

        //build a prefix to track every possible window
        vector<int> prefix(n+1);
        prefix[0]=0;
        for(int i=0; i<n; i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        //for every current indx
        for(int right=0; right<=n; right++){
            //check the front nd remove to shorten
            while(!dq.empty() && prefix[right]-prefix[dq.front()]>=k){
                ans=min(right-dq.front(),ans);
                dq.pop_front();
            }
            //remove from back to keep increasing deque
            while(!dq.empty() && prefix[dq.back()]>=prefix[right]) dq.pop_back();

            dq.push_back(right);
        }
        return ans==INT_MAX? -1:ans;
    }
};