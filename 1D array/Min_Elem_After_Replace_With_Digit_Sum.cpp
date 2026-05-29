#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int minElement(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int n=0;
            while(nums[i]!=0){
                int digit = nums[i]%10;
                n=n+digit;
                nums[i]/=10;
            }
            nums[i]=n;
        }
        int mini=INT_MAX;
        for(int num:nums){
            mini=min(mini,num);
        }
        return mini;
    }
};