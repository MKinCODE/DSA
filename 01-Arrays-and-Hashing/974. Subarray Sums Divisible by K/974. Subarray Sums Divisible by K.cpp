1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        unordered_map<int,int> um;
5        um[0]=1;
6        long long sum=0;
7        int ans=0;
8        for(int x:nums){
9            sum+=x;
10            int curr = ((sum%k)+k)%k;
11
12            if(um.find(curr)!=um.end())
13                ans+=um[curr];
14            um[curr]++;
15        }
16        return ans;
17    }
18};