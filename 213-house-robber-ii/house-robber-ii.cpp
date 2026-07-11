class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){return nums[0];}
        return max(help(nums,0,n-2), help(nums,1,n-1));
    }
private:
    int help(vector<int>&nums, int s, int e){
        int prev = 0, maxRob = 0;
        for(int i = s; i <= e; ++i){
            int temp = max(maxRob, prev + nums[i]);
            prev = maxRob;
            maxRob = temp;
        }
        return maxRob;
    }
};