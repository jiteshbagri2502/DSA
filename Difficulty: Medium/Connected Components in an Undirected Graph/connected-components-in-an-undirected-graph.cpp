class Solution {
  public:
  
  
    void dfs(vector<vector<int>>& adjlist, vector<int>& vis, vector<int>& res, int node){
        vis[node] = 1;
        res.push_back(node);
        for(auto neighbour : adjlist[node]){
            if(!vis[neighbour]){
                dfs(adjlist, vis, res, neighbour);
            }
        }
    }
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> result;
        vector<int> vis(V,0);
        vector<vector<int>> adjlist(V);
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            adjlist[v].push_back(u);
            adjlist[u].push_back(v);
        }
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                vector<int> res;
                dfs(adjlist,vis, res, i);
                result.push_back(res);
            }
        }
        return result;
        
    }
};
