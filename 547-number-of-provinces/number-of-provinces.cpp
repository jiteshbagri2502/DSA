class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, vector<int>& vis, int i, int n){
        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while(!q.empty()){
            int currnode = q.front();
            q.pop();

            for(int j = 0; j < n; j++){
                if(isConnected[currnode][j] && !vis[j]){
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> vis(n,0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                bfs(isConnected,vis,i,n);
            }
        }
        return count;
    }
};