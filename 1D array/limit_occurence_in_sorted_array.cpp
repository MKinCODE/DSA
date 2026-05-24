#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
        }
        vector<int> arr(maxi + 1, 0);
        for(int i=0;i<n;i++){
            if(arr[nums[i]]<=k) arr[nums[i]]++;
        }
        for(int i=0;i<=maxi;i++){
            if(arr[i]==0) continue;
            else{
            while(arr[i]!=0){
                ans.push_back(i);
                arr[i]--;
            } 
            }
        }
        return ans;
    }
};

//space optimised
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.empty()) return ans;
        int n=nums.size();
        int count=1;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]) count++;
            else{count=1;}
            if(count<=k) ans.push_back(nums[i]);
        }
        return ans;
    }
};