class Solution {
public:
    void dfs(vector<vector<int>>& vis,vector<vector<char>>& board, int row, int col){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0  && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && board[nr][nc] == 'O'){
                dfs(vis,board,nr,nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(vis,board,i,0);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(vis,board,i,m-1);
            }
        }
        for(int i = 0; i < m; i++){
            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(vis,board,0,i);
            }
        }
        for(int i = 0; i < m; i++){
            if(!vis[n-1][i] && board[n-1][i] == 'O'){
                dfs(vis,board,n-1,i);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};