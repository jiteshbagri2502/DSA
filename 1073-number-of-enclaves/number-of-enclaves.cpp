class Solution {
public:

    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis, int row, int col){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int dr[] = {-1,-0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && grid[nr][nc]){
                dfs(grid,vis,nr,nc);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(grid,vis,i,0);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(grid,vis,i,m-1);
            }
        }

        for(int i = 0; i < m; i++){
            if(!vis[0][i] && grid[0][i] == 1){
                dfs(grid,vis,0,i);
            }
        }

        for(int i = 0; i < m; i++){
            if(!vis[n-1][i] && grid[n-1][i] == 1){
                dfs(grid,vis,n-1,i);
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};