class Solution {
  public:
    bool help(vector<int>& arr, vector<vector<int>>& dp, int i, int target){
        if(target == 0){
            return true;
        }
        if(i == 0){
            return arr[0] == target;
        }
        
        if(dp[i][target] != -1){return dp[i][target];}
        
        bool notTake = help(arr,dp,i-1,target);
        bool take = false;
        if(arr[i] <= target){
            take = help(arr,dp,i-1,target-arr[i]);
        }
        return dp[i][target] = take||notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return help(arr,dp, n-1, sum);
        
    }
};