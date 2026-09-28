1class Solution {
2public:
3    vector<int> rearrangeArray(vector<int>& nums) {
4        int n=nums.size();
5        int maxnumber = *max_element(nums.begin(),nums.end());
6        vector<int> freq(maxnumber+1,0);
7        for(int i=0; i<n; i++){
8            freq[nums[i]]++;
9        }
10        vector<int> ans;
11        while(ans.size()!=n){
12            for(int i=0; i<=maxnumber; i++){
13                if(freq[i]>0) ans.push_back(i);
14                freq[i]--;
15            }
16        }
17        
18        return ans;
19    }
20};