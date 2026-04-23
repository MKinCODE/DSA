#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        int prefix = 0;
        int minvalue=__INT_MAX__;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            minvalue=min(minvalue,prefix);
        }
        if(minvalue>=1) return 1;
        return 1-minvalue;
    }
};