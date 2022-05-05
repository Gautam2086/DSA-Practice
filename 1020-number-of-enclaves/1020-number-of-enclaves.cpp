class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if(i<0 ||j<0 || i>=m || j>=n || grid[i][j] != 1 ) {
            return;
        } 
        // Sink the island
        grid[i][j]= 0;
    
        dfs(grid, i+1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i, j-1, m, n);
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {

        int ans= 0;
        
        int m= grid.size();
        int n= grid[0].size();
        
        // Sink all the Islands on the boundary and their connections.
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if( (i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j] == 1)
                    dfs(grid, i, j, m, n);
            }
        }
        
        for(auto x: grid) {
            for(auto y: x) {
                if(y==1)
                    ans++;
            }
        }
        
        return ans;
    }
};