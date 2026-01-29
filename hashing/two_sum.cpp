#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        int need;
        for(int i=0;i<nums.size();i++){
             need=target-nums[i];            //check need of ith element
            if(um.find(need)!=um.end()){     //if need is fullfilled by any other element in map
                return {um[need],i};         // return the i and the value(index of element) from map
            }
            um[nums[i]]=i;                   //save the element as key with value as its index
        } 
        return {};
    }
};