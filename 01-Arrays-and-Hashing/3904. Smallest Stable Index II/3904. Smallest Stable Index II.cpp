1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<int> suffixmin(n,0);
6        int mintill=INT_MAX;
7        for(int i=n-1; i>=0; i--){
8            if(nums[i]<mintill){
9                mintill=nums[i];
10            }
11            suffixmin[i]=mintill;
12        }
13        int maxtill=INT_MIN;
14        for(int i=0; i<n; i++){
15            maxtill=max(maxtill,nums[i]);
16            if(maxtill-suffixmin[i]<=k) return i;
17        }
18        return -1;
19    }
20};