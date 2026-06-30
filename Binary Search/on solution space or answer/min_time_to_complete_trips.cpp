#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool can(vector<int>& time, int totalTrips, long long bustime){
        long long trips=0;
        for(int t:time){
            trips+=bustime/t;
        }
        return trips>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans=0;
        long long low=1;
        long long high=1LL*totalTrips*(*min_element(time.begin(),time.end()));
        while(low<=high){
            long long mid = low+(high-low)/2;
            if(can(time,totalTrips,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};