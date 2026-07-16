class Solution {
  public:
  
    int help(vector<int>& arr, vector<vector<int>>& dp, int i, int target){
        if(i == 0){
            if(target == 0 && arr[i] == 0){return 2;}
            if (target == 0 || target == arr[i]) return 1;
            return 0;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        int notTake = help(arr,dp,i-1,target);
        int take = 0;
        if(arr[i] <= target){
            take = help(arr,dp,i-1,target-arr[i]);
        }
        return dp[i][target] = notTake + take;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return help(arr,dp,n-1,target);
    }
};