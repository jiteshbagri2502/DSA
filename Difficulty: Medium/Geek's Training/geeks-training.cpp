class Solution {
  public:
  
  
  
  
  
  //recursion code
  /*
    int help(vector<vector<int>>& mat, int day, int last){
        if(day == 0){
            int maxi = 0;
            for(int i = 0; i < 3; i++){
                if(i != last){
                    maxi = max(maxi, mat[0][i]);
                }
            }
            return maxi;
        }
        int maxi = 0;
        for(int i = 0; i < 3; i++){
            if( i != last){
                int points = mat[day][i] + help(mat, day-1, i);
                maxi = max(maxi,points);
            }
        }
        return maxi;
    }
    */
    
    
    int help(vector<vector<int>>& mat, vector<vector<int>>& dp, int day, int last){
        if(day == 0){
            int maxi = 0;
            for(int i = 0; i < 3; i++){
                if(i != last){
                    maxi = max(maxi, mat[0][i]);
                }
            }
            return maxi;
        }
        if(dp[day][last] != -1){
            return dp[day][last];
        }
        int maxi = 0;
        for(int i = 0; i < 3; i++){
            if(i != last){
                int points = mat[day][i] + help(mat,dp,day-1,i);
                maxi = max(points, maxi);
            }
        }
        dp[day][last] = maxi;
        return dp[day][last];
    }
    
    
    
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        //return help(mat,n-1,3);
        vector<vector<int>> dp(n, vector<int>(4,-1));
        
        return help(mat,dp,n-1,3);
        
        
    }
};