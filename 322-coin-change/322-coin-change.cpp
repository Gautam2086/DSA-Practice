class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n= coins.size();
        int t[n+1][amount+1];
        
        for(int i=0; i<n+1; i++) {              // initialize 0th column
            t[i][0]=0;                          // when coin array is 0
        } 
        for(int j=1; j<amount+1; j++) {         // initialize 0th row
            t[0][j]= INT_MAX-1;                 // when amount is 0
        }
        
        for(int i=1,j=1; j<amount+1; j++)       // initialize 1st row
        {
            if(j % coins[0] ==0)
                t[i][j]= j/coins[0];
            else
                t[i][j]= INT_MAX-1;
        }
        
        for(int i=2; i<n+1; i++)
        {
            for(int j=1; j<amount+1; j++)
            {
                if(coins[i-1] <= j)
                    t[i][j]=min(1+t[i][j-coins[i-1]], t[i-1][j] );
                else
                    t[i][j]= t[i-1][j];
            }
        }
        
    // If that amount of money cannot be made up by any combination of the coins
        if(t[n][amount] == INT_MAX-1)       
            return -1;
        else
            return t[n][amount];
    }
};