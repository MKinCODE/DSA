#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//brute force approach
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            if(sum==goal){count++;}
        }
    }
    return count;
    }
};

//hashing approach
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int curr=0;
        mp[0]=1;
        int answer=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(mp.find(curr-goal)!=mp.end()){answer+=mp[curr-goal];}
            mp[curr]++;
        }
        return answer;
    }
}; 

// optimal approach: exact=atmost_subarray-atmost_subarray(goal-1) using concept of max-consecutive-oneslll