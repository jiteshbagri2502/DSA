class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first = bs(arr,target,true);
        int last = bs(arr,target,false);
        if(first == -1){return 0;}
        return last - first + 1;
    }
    
    int bs(vector<int>& arr, int target, bool isleft){
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(target > arr[mid]){
                low = mid+1;
            }
            else if(target < arr[mid]){
                high = mid-1;
            }
            else{
                if(isleft){
                    ans = mid;
                    high = mid-1;
                }
                else{
                    ans = mid;
                    low = mid+1;
                }
            }
        }
        return ans;
    }
};
