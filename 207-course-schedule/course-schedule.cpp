class Solution {
public:

    bool dfs(vector<int> adj[], vector<int>& vis, vector<int>& path, int i){
        vis[i] = path[i] = 1;
        for(auto it : adj[i]){
            if(!vis[it]){
                if(!dfs(adj,vis,path,it)){return false;}
            }
            else if(path[it]){return false;}
        }
        path[i] = 0;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto &it: prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(!dfs(adj,vis,path,i)){
                    return false;
                }
            }
        }
        return true;
    }
};