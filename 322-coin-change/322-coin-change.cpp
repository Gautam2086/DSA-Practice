class Solution {
public:
    int knapsack(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        
        if(i>=coins.size() && amount == 0)                  // Base case when amt==0
            return 0;   
        
        if(i>=coins.size())                                 // we aint able to make upto amt           
            return INT_MAX-1;                               // so we need INT_MAX coins
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        if(coins[i] > amount)                               // check of coin[i] > amt
            return dp[i][amount]= knapsack(i+1, coins, amount, dp);
        else                                                // reutrn min of both conditions
            return dp[i][amount]= min(1+knapsack(i, coins, amount-coins[i], dp), 
                                        knapsack(i+1, coins, amount, dp));
        
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        
        int ans= knapsack(0, coins, amount, dp);
        return (ans==INT_MAX-1) ? -1 : ans;
    }
};