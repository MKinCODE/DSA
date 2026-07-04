#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size()-1;
        if(k>n+1) return -1;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int x:nums){
            minHeap.push(x);

            if(minHeap.size()>k) 
                minHeap.pop();
        }
        return minHeap.top();
    }
};