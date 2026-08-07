class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxi = arr[0];
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > maxi){
                maxi = arr[i];
            }
        }
        return maxi;
    }
};
