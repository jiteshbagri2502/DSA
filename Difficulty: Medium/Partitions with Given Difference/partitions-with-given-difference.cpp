class Solution {
  public:
  
    int help(vector<int>& arr, vector<vector<int>>& dp, int i, int sum){
        if(i == 0){
            if(!sum && !arr[i]) return 2;
            if(!sum || arr[i] == sum) return 1;
            return 0;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int notTake = help(arr,dp,i-1,sum);
        int take = 0;
        if(arr[i] <= sum){
            take = help(arr,dp,i-1,sum-arr[i]);
        }
        return dp[i][sum] = take + notTake;
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int it: arr){
            sum += it;
        }
        if(sum < diff || (sum+diff)%2 != 0){
            return 0;
        }
        sum = (sum+diff)/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return help(arr,dp,n-1,sum);
        
    }
};