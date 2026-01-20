#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> us;
        int n = nums.size();
        for(int i=0;i<n;i++){
            us.insert(nums[i]);
        }
        for(int i=0;i<=n;i++){
            if(us.find(i)==us.end()){
                return i;
            }
        }
        return -1;
    }
};

// optimised solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        int actual;
         actual=n*(n+1);
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        return (actual-2*sum)/2;
    }
};
