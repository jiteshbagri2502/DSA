class Solution {
public:

    int help(vector<int>& nums, int idx, int sum){
        if(idx == 0){
            if(sum == 0 && nums[idx] == 0){return 2;}
            if(sum == 0 || sum == nums[idx]){return 1;}
            return 0;
        }
        int notTake = help(nums,idx-1,sum);
        int take = 0;
        if(nums[idx] <= sum){
            take = help(nums,idx-1,sum-nums[idx]);
        }
        return take + notTake;
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
        return help(nums,n-1,total);
    }
       
};