#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int div, int threshold){
        int currsum=0;
        for(int num:nums){
            currsum+=(num+div-1)/div;
        }
        return currsum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(check(nums,mid,threshold)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};