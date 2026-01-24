#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();
        int left=0;
        int right=n-1;
        int k=n-1;
        vector<int> ans(n);
        while(left<=right){
            int l=nums[left]*nums[left];
            int r=nums[right]*nums[right];

            if(l>r){
                ans[k--]=l;
                left++;
            }
            else{
                ans[k--]=r;
                right--;
            }
        }
        return ans;
        
}};