#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        vector<int> dp(n+1);

        dp[1]=1;
        dp[2]=2;

        for(int i=3; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

//space optimised dp
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        int prev2=1;
        int prev1=2;

        for(int i=3; i<=n; i++){
           int curr = prev1 + prev2;

           prev2=prev1;
           prev1=curr;
        }
        return prev1;
    }
};