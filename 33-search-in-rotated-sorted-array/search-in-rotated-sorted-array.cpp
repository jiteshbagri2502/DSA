class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m;
        while(l <= r){
            m = l + (r - l)/2;
            if(target == nums[m]){
                return m;
            }
            else if(nums[m] >= nums[l]){
                if(nums[l] <= target && nums[m] >= target){
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
            else{
                if(nums[m] <= target && nums[r] >= target){
                    l = m + 1;
                }
                else{
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};