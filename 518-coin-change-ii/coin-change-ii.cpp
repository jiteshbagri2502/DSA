class Solution {
public:
    int help(vector<vector<int>>& dp,vector<int>& coins, int i, int amount){
        if(i == 0){
            if(amount % coins[0] == 0){
                return 1;
            }
            return 0;
        }
        if(dp[i][amount] != -1){return dp[i][amount];}
        int notTake = help(dp,coins,i-1,amount);
        int take = 0;
        if(coins[i] <= amount){
            take = help(dp,coins,i,amount-coins[i]);
        }
        return dp[i][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return help(dp,coins,n-1,amount);
    }
};