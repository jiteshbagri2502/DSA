class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){return image;}
        int m = image.size();
        int n = image[0].size();
        int old = image[sr][sc];
        image[sr][sc] = color;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i = 0 ; i < 4; i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && image[nr][nc] == old){
                floodFill(image,nr,nc,color);
            }
        }
        return image;
    }
};