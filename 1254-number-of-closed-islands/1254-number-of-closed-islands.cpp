/*
- First, traverse boundary 
    - if we encounter 0, call dfs
    - convert all Boundary 0s (land) to 1s (water) as they will not be a part of closed island
- Then again apply dfs on whole grid & check for internal 0s ie lands and again call dfs for those 0s
- now count closed islands
*/
class Solution {
public:
    vector<vector<int>> dirs= {
                {-1,0},
        {0,-1},         {0,1},
                {1,0}
    };
    
    bool isValid(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 0) {
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        
        grid[i][j]= 1;
        
        for(auto dir: dirs) {
            int nx= i + dir[0];         // new x co-ordinate
            int ny= j + dir[1];         // new y co-ordinate
            
            if(isValid(grid,nx, ny, n, m)) {
                dfs(grid, nx, ny, n, m);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        // Boundary DFS
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i*j == 0 || i == n-1 || j == m-1) {
                    if(grid[i][j] == 0) {
                        dfs(grid, i, j, n, m);
                    }
                }
            }
        }
        
        int ans= 0;
        // Call dfs in whole grid
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) 
            {
                if(grid[i][j] == 0) {
                    ans++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        
        return ans;
    }
};