class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, int n , vector<bool> &visited){
        if(visited[i]){
            return;
        }
        visited[i]= true;
        for(int j=0;j<n;j++){
            if(j!=i && isConnected[i][j] ){
                dfs(isConnected, j, n,visited );
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);

        int count =0;

        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }
            dfs(isConnected, i , n, visited);
            count++;
        }
        return count;
        
    }
};