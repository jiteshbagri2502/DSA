class Solution {
  public:
  
    int help(vector<vector<int>>& dp,string &s1, string &s2, int i, int j){
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1){return dp[i][j];}
        if(s1[i] == s2[j]){
            return 1 + help(dp,s1,s2,i-1,j-1);
        }
        return dp[i][j] = max(help(dp,s1,s2,i-1,j), help(dp,s1,s2,i,j-1));
    }
  
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(dp,s1,s2,n-1,m-1);
    }
};
