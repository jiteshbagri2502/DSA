class Solution {
  public:
  
    void dfs(vector<int> adj[], vector<int>& vis, stack<int>& st, int i){
        vis[i] = 1;
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(adj,vis,st,it);
            }
        }
        st.push(i);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        stack <int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(adj,vis,st,i);
            }
        }
        vector<int> res;
        for(int i = 0; i < V; i++){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};