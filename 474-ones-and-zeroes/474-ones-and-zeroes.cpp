class Solution {
public:
    // bottom up DP
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int i, j;
        vector<vector<int>> dp(m+1 , vector<int>(n+1));
        
        for(auto &s:strs)
        {
            int x = count(s.begin(),s.end(),'1');
            int y = s.size()-x;
            
            for(i=m; i>=y; i--)
            {
                for(j=n; j>=x; j--)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i-y][j-x]);
                }
            }
        }
        
        return dp[m][n];
    }
};