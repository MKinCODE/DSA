1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int ans=0;
5        for(int x:nums) ans^=x;
6        return ans;
7    }
8};