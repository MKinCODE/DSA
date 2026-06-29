#include<vector>
#include<algorithm>
using namespace std;

//standard
class Solution {
public:
    bool can(vector<int>& piles, int h, int speed){
        long long hours=0;
        for(int x:piles){
            hours+=(x+speed-1)/speed;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(can(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};

//little more optimal not in any terms btw
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;

            long long hours=0;
            for(int x:piles){
            hours+=(x+mid-1)/mid;
            }

            if(hours<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};