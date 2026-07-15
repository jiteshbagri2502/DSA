class Solution {
public:

    bool help(vector<int>& nums,vector<vector<int>>& dp, int i, int sum){
        if(sum == 0){return 1;}
        if(i == 0){return nums[0] == sum;}
        if(dp[i][sum] != -1){return dp[i][sum];}

        bool notTake = help(nums,dp,i-1,sum);
        bool take = false;
        if(nums[i] <= sum){
            take = help(nums,dp,i-1,sum - nums[i]);
        }
        return dp[i][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int it : nums){
            sum+= it;
        }
        if(sum%2 != 0){return false;}
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return help(nums,dp,n-1,sum/2);
    }
};