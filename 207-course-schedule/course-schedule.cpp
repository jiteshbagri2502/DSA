class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<int> adj[numCourses];
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(cnt == numCourses){return true;}
        return false;
    }
};