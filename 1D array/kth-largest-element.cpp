#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        if(k>n+1) return -1;
        return nums[n-k+1];
    }
};