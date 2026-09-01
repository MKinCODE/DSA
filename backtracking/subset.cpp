#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    vector<int> curr;
public:
    void helper(int start, vector<int>& nums){
        ans.push_back(curr);
        for(int i=start; i<nums.size();i++){
            curr.push_back(nums[i]);
            helper(i+1,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(0,nums);
        return ans;
    }
};