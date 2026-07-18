class Solution {
  public:
    int help(vector<vector<int>>& dp, vector<int>& price, int i,int len){
        if(i == 0){
            return price[0]*len;
        }
        if(dp[i][len] != -1){
            return dp[i][len];
        }
        int notTake = help(dp,price,i-1,len);
        int take = 0;
        if(i+1 <= len){
            take = price[i] + help(dp,price,i,len-i-1);
        }
        return dp[i][len] = max(take,notTake);
        
    }
    
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return help(dp,price,n-1,n);
    }
};