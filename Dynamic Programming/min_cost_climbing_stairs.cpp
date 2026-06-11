#include <bits/stdc++.h>
using namespace std;
//space optimized
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int next1=0, next2=0;
        for(int i=n-1; i>=0; i--){
            int curr=cost[i]+min(next1,next2);

            next2=next1;
            next1=curr;
        }
        return min(next1,next2);
    }
};

//tabulization
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+2,0);
        for(int i=n-1; i>=0; i--){
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};

//memoization
class Solution {
public:
    int helper(int index, vector<int>& dp, vector<int>& cost, int n){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        dp[index] = cost[index] + min(helper(index+1,dp,cost,n),helper(index+2,dp,cost,n));
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(helper(0,dp,cost,n),helper(1,dp,cost,n));
    }
};

//recursion
class Solution {
public:
    int helper(int index,vector<int>& cost, int n){
        if(index>=n) return 0;
        return cost[index] + min(helper(index+1,cost,n),helper(index+2,cost,n));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return min(helper(0,cost,n),helper(1,cost,n));
    }
};