1class Solution {
2public:
3    int sumCounts(vector<int>& nums) {
4        vector<int> temp;
5        for(int i=0; i<nums.size(); i++){
6            unordered_set<int> us;
7            for(int j=i; j<nums.size(); j++){
8                us.insert(nums[j]);
9                int curr = us.size();
10                temp.push_back(curr*curr);
11            }
12        }
13        return accumulate(temp.begin(),temp.end(),0);
14    }
15};