#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums, int k, int x){
        int count=1;
        int currsum=0;
        for(int num:nums){
            if(currsum+num<=x) currsum+=num;
            else {
                count++;
                currsum=num;
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans=-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(check(nums,k,mid)) {
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};