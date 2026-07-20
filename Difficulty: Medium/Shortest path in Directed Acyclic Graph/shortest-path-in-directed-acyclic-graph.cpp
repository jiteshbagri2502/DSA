class Solution {
  public:
  
    void topoSort(vector<pair<int,int>> adj[], vector<int>& vis, stack<int>& st, int idx){
        vis[idx] = 1;
        for(auto it: adj[idx]){
            if(!vis[it.first]){
                topoSort(adj,vis,st,it.first);
            }
        }
        st.push(idx);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                topoSort(adj,vis,st,i);
            }
        }
        
        vector<int> dist(V,1e9);
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(dist[node] != 1e9){
                for(auto it: adj[node]){
                    int v = it.first;
                    int wt = it.second;
                
                    if(dist[v] > wt + dist[node]){
                        dist[v] = wt + dist[node];
                    }
                }
            }
        }
        for(int i = 0; i < V; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }
};
