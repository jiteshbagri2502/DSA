class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int i) {
        vis[i] = 1;
        for (int j = 0; j < vis.size(); j++) {
            if (isConnected[i][j] && !vis[j]) {
                dfs(isConnected, vis, j);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(isConnected, vis, i);
            }
        }
        return count;
    }
};