class Solution {
public:

    int help(vector<vector<int>>& dp, vector<int>& nums, int idx, int sum){
        if(idx == 0){
            if(sum == 0 && nums[idx] == 0){return 2;}
            if(sum == 0 || sum == nums[idx]){return 1;}
            return 0;
        }
        if(dp[idx][sum] != -1){return dp[idx][sum];}
        int notTake = help(dp,nums,idx-1,sum);
        int take = 0;
        if(nums[idx] <= sum){
            take = help(dp,nums,idx-1,sum-nums[idx]);
        }
        return dp[idx][sum] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int it: nums){
            total+=it;
        }
        if(abs(target) > total || (total + target)%2 != 0){
            return 0;
        }
        total = (total + target)/2;
        vector<vector<int>> dp(n,vector<int>(total+1,-1));
        return help(dp,nums,n-1,total);
    }
       
};