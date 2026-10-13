1class Solution {
2public:
3    long long maxAlternatingSum(vector<int>& nums) {
4        int n = nums.size();
5        for(int i=0; i<n; i++){
6            nums[i]=nums[i]*nums[i];
7        }
8        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
9        long long sum = 0;
10        for(int i=n/2; i<n; i++) sum+=nums[i];
11        for(int i=0; i<(n/2); i++){
12            sum-=nums[i];
13        }
14        return sum;
15    }
16};