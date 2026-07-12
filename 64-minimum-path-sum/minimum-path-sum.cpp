class Solution {
public:

    int help(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n){
        if(m < 0 || n < 0){return 1e9;}
        if(m == 0 && n == 0){return grid[0][0];}
        if(dp[m][n] != -1){return dp[m][n];}
        int left = grid[m][n]  + help(grid,dp, m, n-1);
        int up = grid[m][n] + help(grid,dp,m-1,n);
        return dp[m][n] = min(left,up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n, -1));
        return help(grid,dp,m-1,n-1);
    }
};