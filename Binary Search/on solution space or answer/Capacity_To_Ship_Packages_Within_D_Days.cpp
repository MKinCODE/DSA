#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool can(vector<int>& weights, int days, long long capacity){
        int mindays=1;
        long long conv=0;
        for(int w:weights){
            if(conv+w<=capacity) conv+=w;
            else{
                conv=w;
                mindays++;
            }
            if(mindays>days) return false;
        }
        return mindays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long low = *max_element(weights.begin(), weights.end());;
        long long high=accumulate(weights.begin(),weights.end(),0LL);
        while(low<=high){
            long long mid= low+(high-low)/2;
            if(can(weights,days,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};