class Solution {
public:

    int help(vector<vector<int>>& dp,vector<int>& coins, int idx, int amount){
        if(idx == 0){
            if(amount%coins[0] == 0){
                return amount/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        int notTake = help(dp,coins,idx-1,amount);
        int take = 1e9;
        if(amount >= coins[idx]){
            take = help(dp,coins,idx,amount-coins[idx])+1;
        }
        return dp[idx][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res = help(dp,coins,n-1,amount);
        if(res == 1e9){
            return -1;
        }
        return res;
    }
};