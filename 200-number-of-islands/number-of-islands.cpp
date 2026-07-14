class Solution {
public:

    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(grid,vis,nrow,ncol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};