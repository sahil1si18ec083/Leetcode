class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int oldcolor, int n , int m ) {
        if(sr<0 || sc<0 || sr>=n || sc>=m){
            return ;
        }
        if(oldcolor!=image[sr][sc]){
            return ;
        }
        image[sr][sc]= color;
        dfs(image, sr-1, sc, color, oldcolor, n, m);
        dfs(image, sr+1, sc, color, oldcolor, n, m);
        dfs(image, sr, sc-1, color, oldcolor, n, m);
        dfs(image, sr, sc+1, color, oldcolor, n, m);


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int oldcolor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        if(oldcolor==color) return  image;

        dfs(image, sr, sc, color, oldcolor, n, m);

        return image;
        
    }
};