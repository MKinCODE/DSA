//memoization
class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return 1e9;

        if (dp[amount] != -1)
            return dp[amount];

        int ans = 1e9;

        for (int coin : coins) {
            ans = min(ans, 1 + helper(coins, amount - coin, dp));
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);

        int ans = helper(coins, amount, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};

//recursive approach
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        int ans=1e9;
        int temp=INT_MAX;
        for(int coin:coins){
            temp=coinChange(coins,amount-coin);
            if(temp==INT_MAX) continue;
            ans=min(ans,1+temp);
        }
        return ans;
    }
};