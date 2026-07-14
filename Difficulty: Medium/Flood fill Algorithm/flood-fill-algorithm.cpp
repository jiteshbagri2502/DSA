class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        int m = image.size();
        int n = image[0].size();
        int old = image[sr][sc];
        if(newColor==old){
            return image;
        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = newColor;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && image[nr][nc] == old){
                    q.push({nr,nc});
                    image[nr][nc] = newColor;
                }
            
            }
        }
        return image;
    }
};