class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<int> adj[numCourses];
        for(auto &it: prerequisites){
            int u = it[0];
            int v = it[1];
            indegree[u]++;
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> res;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(res.size() == numCourses){
            return res;
        }
        return {};
    }
};