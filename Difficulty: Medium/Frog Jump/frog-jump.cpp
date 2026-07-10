class Solution {
  public:
  
  
  //recursive code
  
  /*
    int help(vector<int>& height, int i){
        if(i == 0){
            return 0;
        }
        if(i == 1){
            return abs(height[1] - height[0]);
        }
        if(i > 1){
            int oneJump = help(height, i-1) + abs(height[i] - height[i-1]);
            int twoJump = help(height, i-2) + abs(height[i] - height[i-2]);
            return min(oneJump, twoJump);
        }
    }
  */
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        //return help(height, n-1); RECURSIVE CODE
        
        if(n < 2){return 0;}
        vector<int> dp(n,0);
        dp[1] = abs(height[1] - height[0]);
        
        for(int i = 2; i < n; i++){
            int oneJump = dp[i-1] + abs(height[i] - height[i-1]);
            int twoJump = dp[i-2] + abs(height[i] - height[i-2]);
            dp[i] = min(oneJump, twoJump);
            
        }
        return dp[n-1];
        
    }
};