#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int n=nums.size();
        um[0]=1;
        int count=0;
        int prefix=0;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            if(um.find(prefix-k)!=um.end()){
                count+=um[prefix-k];
            }
            if(um.find(prefix)!=um.end()) um[prefix]++;
            else um[prefix]=1;
        }
        return count;
    }
};