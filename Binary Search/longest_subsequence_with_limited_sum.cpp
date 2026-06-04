#include<vector>
#include<algorithm>
using namespace std;
//more optimal:
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1; i<n; i++) nums[i]=nums[i-1]+nums[i];

        vector<int> ans;
        for(int q:queries){
            ans.push_back(upper_bound(nums.begin(),nums.end(),q) - nums.begin());   //upper_bound() returns iterator of number greater than query passed into it. and nums.begin() is subtracted to convert it to int from iterator.
        }
        return ans;
    }
};
//less optimal:
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1; i<n; i++) prefix[i]=prefix[i-1]+nums[i];

        int m=queries.size();
        vector<int> ans(m);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(queries[i]>=prefix[j]) ans[i]=j+1;
            }
        }
        return ans;
    }
};