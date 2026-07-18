class Solution {
  public:
  int help(vector<vector<int>>& dp,vector<int>& val, vector<int>& wt, int i, int capacity){
      if(i == 0){
          return val[0]*(capacity/wt[0]);
      }
      if(dp[i][capacity] != -1){
            return dp[i][capacity]; 
      }
      int notTake = help(dp,val,wt,i-1,capacity);
      int take = 0;
      if(wt[i] <= capacity){
          take = val[i] + help(dp,val,wt,i,capacity - wt[i]);
      }
      return dp[i][capacity] = max(take,notTake);
  }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return help(dp,val,wt,n-1,capacity);
    }
};