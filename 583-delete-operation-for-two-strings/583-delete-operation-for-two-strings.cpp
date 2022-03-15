class Solution {
public:

    int getLcs(string& s1, string &s2, int i, int j, vector<vector<int>>& dp) {
        
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j]= 1+getLcs(s1, s2, i-1, j-1, dp);
        else 
            return dp[i][j]= max( getLcs(s1, s2, i-1, j, dp), getLcs(s1, s2, i, j-1, dp));
        
    }
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        
        int lcs= getLcs(word1, word2, word1.length()-1, word2.length()-1, dp);        
        int remove= word1.size() + word2.size() - 2*lcs;
        
        return remove;
    }
};