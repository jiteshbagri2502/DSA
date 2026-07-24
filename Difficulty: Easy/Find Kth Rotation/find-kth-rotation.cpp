class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low = 0;
        int high = arr.size()-1;
        int ans = 1e9;
        int idx = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] >= arr[low]){
                if(arr[low] < ans){
                    idx = low;
                    ans = arr[low];
                }
                low = mid+1;
            }
            else{
                if(arr[mid] < ans){
                    ans = arr[mid];
                    idx = mid;
                }
                high = mid-1;
            }
        }
        return idx;
        
    }
};
