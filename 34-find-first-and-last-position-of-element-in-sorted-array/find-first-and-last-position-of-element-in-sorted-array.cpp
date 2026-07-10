class Solution {
public:
    int first(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int ans = -1;
        int m;
        while(l <= r){
            m = l + (r - l)/2;
            if(nums[m] == target){
                ans = m;
                r = m - 1;
            }
            else if(nums[m] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
    int last(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int ans = -1;
        int m;
        while(l <= r){
            m = l + (r - l)/2;
            if(nums[m] == target){
                ans = m;
                l = m + 1;
            }
            else if(nums[m] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target), last(nums,target)};
    }
};