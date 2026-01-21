#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us(nums1.begin(),nums1.end());
        unordered_set<int> ans;
        for(int i=0;i<nums2.size();i++){
            if(us.find(nums2[i])!=us.end()){
                ans.insert(nums2[i]);
            }
        }
        vector<int> v(ans.begin(),ans.end());
    return v;
    }
};

//further optimisation of space
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us(nums1.begin(),nums1.end());
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            if(us.find(nums2[i])!=us.end()){
                ans.push_back(nums2[i]);
                us.erase(nums2[i]);          //once it is found we'll erase it
            }
        }
       // vector<int> v(ans.begin(),ans.end()); 
    return ans;
    }
};