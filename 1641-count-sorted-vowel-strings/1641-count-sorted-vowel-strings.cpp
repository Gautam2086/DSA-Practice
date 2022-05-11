class Solution {
public:
    vector<char> vowels= {'a', 'e', 'i', 'o', 'u'};
    vector<vector<int>> dp;
    
    int helper(int n, int idx) {
        if(n == 0) {
            return 1;
        }
        if(idx >= vowels.size())
            return 0;
        if(dp[n][idx] != -1)
            return dp[n][idx];
        
        int op1= helper(n-1, idx);
        int op2= helper(n, idx+1);
        
        return dp[n][idx]= op1+op2;
    }
    
    int countVowelStrings(int n) {
        dp.assign(n+1, vector<int> (6, -1));
        int i= 0;
        
        int ans= helper(n, i);
        
        return ans;
    }
};