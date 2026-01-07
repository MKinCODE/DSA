#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res = nums[0];
        int bestmin = nums[0];           
        int maxEnding = nums[0];   
        int mine=nums[0];  
        int n=nums.size();
        int total=nums[0];
    for (int i = 1; i < n; i++) {
        total+=nums[i];
        maxEnding = max(nums[i], maxEnding + nums[i]);
        res = max(res, maxEnding);

        mine = min(nums[i], mine + nums[i]);
        bestmin = min(bestmin, mine);
    }
    int wrap = total - bestmin;
    if(total==bestmin){return res;}
    else{
        return max(res,wrap);
    }
    }
};