1class Solution {
2public:
3    bool checkSubarraySum(vector<int>& nums, int k) {
4        int n = nums.size();
5        unordered_map<int,int> um;
6        for(int i=1; i<n; i++){
7            nums[i]+=nums[i-1];
8        }
9        um[0]=-1;
10        for(int i=0; i<n; i++){
11            if(um.find(nums[i]%k)!=um.end() && i-um[nums[i]%k]>1) return true;
12            if (um.find(nums[i]%k) == um.end()) {
13                um[nums[i]%k]=i;
14            }
15        }
16        return false;
17    }
18};