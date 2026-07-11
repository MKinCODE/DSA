#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        int ans=__INT_MAX__;
        int sum=0;
         
        for(int right=0; right<nums.size(); right++){
            sum+=nums[right];

            while(sum>=target){
                ans=min(ans,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return ans==__INT_MAX__? 0:ans;
    }
};