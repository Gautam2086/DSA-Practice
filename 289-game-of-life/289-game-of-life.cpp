class Solution {
public:
    int neighborOnes(vector<vector<int>>& brd, int i, int j) {
        
        int r= brd.size();
        int c= brd[0].size();
        int ones= 0;
        
        if(j>0 && brd[i][j-1] == 1)                       // left
            ones++;
        
        if(j<c-1 && brd[i][j+1] == 1)                     // right
            ones++;
        
        if(i>0 && brd[i-1][j] == 1)                       // up
            ones++;
        
        if(i<r-1 && brd[i+1][j] == 1)                     // down
            ones++;
        
        if(i>0 && j>0 && brd[i-1][j-1] == 1)              // diagonal Upleft
            ones++;
        
        if(i<r-1 && j<c-1 && brd[i+1][j+1] == 1)          // diagonal Downright
            ones++;
        
        if(i>0 && j<c-1 && brd[i-1][j+1] == 1)            // diagonal Upright
            ones++;
        
        if(i<r-1 && j>0 && brd[i+1][j-1] == 1)            // diagonal Downleft
            ones++;
        
        return ones;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> brd = board;
        
        for(int i=0; i<brd.size(); i++) {
            for(int j=0; j<brd[0].size(); j++)
            {
                int one= neighborOnes(brd, i, j);
                
                if(brd[i][j] == 1) 
                {
                    if(one>=2 && one<=3)              // live
                        board[i][j]= 1;
                    else                                // die
                        board[i][j]= 0;
                }
                else {
                    if(one == 3)                        // live
                        board[i][j]= 1;
                }
            }
        }
    }
};