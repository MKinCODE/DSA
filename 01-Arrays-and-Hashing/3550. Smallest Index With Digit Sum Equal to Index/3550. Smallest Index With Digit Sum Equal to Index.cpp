1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        for(int i=0; i<nums.size(); i++){
5            int digit = nums[i];
6            int sum=0;
7            while(digit!=0){
8                sum+=digit%10;
9                digit/=10;
10            }
11            if(sum==i) return i;
12        }
13        return -1;
14    }
15};