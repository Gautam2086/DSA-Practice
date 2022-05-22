class Solution {
public:
    
    int helper(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        
        if(amount == 0)                                     // Base case when amt==0
            return 1;   
        
        if(i>=coins.size() || amount<0)                     // we aint able to make upto amt        
            return 0;                                       // so we need INT_MAX coins
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        int ways1= 0;
        int ways2= 0; 
        
        if(coins[i] <= amount)                               // check of coin[i] <= amt
            ways1 += helper(i, coins, amount-coins[i], dp); 

        ways2 += helper(i+1, coins, amount, dp);              // this optn is always available
        
        return dp[i][amount]= ways1+ways2;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        
        return helper(0, coins, amount, dp);
    }
};