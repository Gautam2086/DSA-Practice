class Solution {
public:
    //int mod= 2 + 1e9;
    
    int helper(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        
        if(i>=0 && j>=0 && mat[i][j] == 1)                  // Dead cell
            return 0;
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up= helper(i-1, j, mat, dp);
        int left= helper(i, j-1, mat, dp);
        
        return dp[i][j]= (up+left) ;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return (helper(m-1, n-1, obstacleGrid, dp));
    }
};