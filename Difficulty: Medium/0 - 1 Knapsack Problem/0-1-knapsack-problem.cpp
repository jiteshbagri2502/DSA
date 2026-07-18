class Solution {
  public:
  
    int help(vector<vector<int>>& dp, vector<int> &val, vector<int> &wt, int i, int j){
        if(j == 0){
            return 0;
        }
        if(i == 0){
            return j >= wt[0] ? val[0] : 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int notTake = help(dp,val,wt,i-1,j);
        int take = 0;
        if(wt[i] <= j){
            take = val[i] + help(dp,val,wt,i-1,j-wt[i]);
        }
        return dp[i][j] = max(take,notTake);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return help(dp,val,wt,n-1,W);
    }
};