#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==1 && nums[0]!=target) return {-1,-1};
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high){
            if(nums[high]!=target) high--;
            if(nums[low]!=target) low++;
            if(nums[low]==target && nums[high]==target) return {low,high};
        }
        return {-1,-1};
    }
};