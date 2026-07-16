class Solution {
public:

    bool dfs(vector<vector<int>>& graph,vector<int>& color, int idx, int currcolor){
        for(auto it: graph[idx]){
            if(color[it] == -1){
                color[it] = !currcolor;
                if(!dfs(graph,color,it, color[it])){
                    return false;
                }
            }
            else if(color[it] == currcolor){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(graph,color,i,0)){
                    return false;
                }
            }
        }
        return true;
    }
};