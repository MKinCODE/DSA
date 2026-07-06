#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        stack<int> st;
        unordered_map<int,int> mp;
        for(int num:nums2){
            while(!st.empty() && num>st.top()){
                mp[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        for(int num:nums1){
            answer.push_back(mp[num]);
        }
       return answer;
    }
};

//brute force :
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        int n=nums1.size();
        int m=nums2.size();

       for(int i=0;i<n;i++){
        int ans=-1;
        for(int j=0;j<m;j++){
            if(nums1[i]==nums2[j]){
                for(int x=j+1; x<m;x++){
                    if(nums2[x]>nums2[j]){
                        ans=nums2[x];
                        break;
                    }
                }
                break;
            }
        }
        answer.push_back(ans);
       }
       return answer;
    }
};