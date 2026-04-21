#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        // res → stores maximum subarray sum (normal Kadane)
        int res = nums[0];
        
        // bestmin → stores minimum subarray sum (for circular case)
        int bestmin = nums[0];           
        
        // maxEnding → max subarray sum ending at current index
        int maxEnding = nums[0];   
        
        // mine → min subarray sum ending at current index
        int mine = nums[0];  
        
        int n = nums.size();
        
        // total → total sum of array (needed for circular calculation)
        int total = nums[0];

        for (int i = 1; i < n; i++) {
            
            // Keep track of total sum
            total += nums[i];

            // ----- KADANE FOR MAX SUBARRAY -----
            // Either start new subarray OR extend previous
            maxEnding = max(nums[i], maxEnding + nums[i]);
            
            // Update overall maximum
            res = max(res, maxEnding);

            // ----- KADANE FOR MIN SUBARRAY -----
            // Either start new subarray OR extend previous (for minimum)
            mine = min(nums[i], mine + nums[i]);
            
            // Update overall minimum
            bestmin = min(bestmin, mine);
        }

        // Circular case:
        // Max circular sum = total sum - minimum subarray sum
        int wrap = total - bestmin;

        // Edge case:
        // If all elements are negative,
        // total == bestmin → wrap becomes 0 (invalid)
        // so return normal max (res)
        if (total == bestmin) {
            return res;
        }
        else {
            // Return best of normal and circular
            return max(res, wrap);
        }
    }
};