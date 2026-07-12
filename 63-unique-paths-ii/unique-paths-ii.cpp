class Solution {
public:
    int help(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n){
        if(m < 0 || n < 0){return 0;}
        if(grid[m][n]){return 0;}
        if(m == 0 && n== 0){
            return 1;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int left = help(grid, dp, m, n-1);
        int up = help(grid, dp, m-1, n);
        return dp[m][n] = left + up;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return help(obstacleGrid, dp, m-1, n-1);
    }
};