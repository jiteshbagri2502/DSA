class Solution {
  public:
  
    bool bfs(vector<int> adjlist[],vector<int>& vis, int source ){
        queue<pair<int,int>> q;
        q.push({source,-1});
        vis[source] = 1;
        while(!q.empty()){
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adjlist[curr]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,curr});
                }
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adjlist[V];
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<int> vis(V,0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(bfs(adjlist,vis,i)){
                    return true;
                }
            }
        }
        return false;
        
    }
};