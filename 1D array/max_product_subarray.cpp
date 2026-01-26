#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxhere=nums[0];
        int minhere=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            
            if(nums[i]<0){swap(maxhere,minhere);};

            maxhere=max(nums[i],maxhere*nums[i]);
            minhere=min(nums[i],minhere*nums[i]);

            ans=max(ans,maxhere);
        }
        return ans;
    }
};