#include<vector>
#include<algorithm>
using namespace std;
//most optimal
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    void recurse(vector<int>& nums, vector<bool>& seen, int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(seen[i]) continue;
            if(i>0 && nums[i-1]==nums[i] && !seen[i-1]) continue;
            temp.push_back(nums[i]);
            seen[i]=true;
            recurse(nums,seen,n);
            seen[i]=false;
            temp.pop_back(); 
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<bool> seen(n,false);
        sort(nums.begin(),nums.end());
        recurse(nums,seen,n);
        return ans;
    }
};