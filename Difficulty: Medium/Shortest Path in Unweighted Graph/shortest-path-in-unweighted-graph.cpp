class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<int> adj[V];
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V,0);
        queue<pair<int,int>> q;
        q.push({src,0});
        vis[src] = 1;
        while(!q.empty()){
            int curr = q.front().first;
            int step = q.front().second;
            q.pop();
            for(auto it: adj[curr]){
                if(it == dest){
                    return step+1;
                }
                else if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,step+1});
                }
            }
        }
        return -1;
    }
};
