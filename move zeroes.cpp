#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int pos=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
              swap(nums[i],nums[pos]);
              pos++;
            }
        }
    }
};
int main(){
    Solution s;
    vector<int> t(5);
    t[0]=1;
    t[1]=0;
    t[2]=3;
    t[3]=0;
    t[4]=0;
    s.moveZeroes(t);
    for(int i=0;i<5;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}