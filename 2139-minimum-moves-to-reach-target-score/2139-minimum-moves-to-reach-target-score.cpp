class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        int start= 1;
        if(target == start || maxDoubles == 0)          // Edge case
            return target-1;            
        
        int moves= 0;
        
        // if there are no maxDoubles left now, then we can only subtract 1 from target
        while(target > start && maxDoubles > 0)
        {
            if(target % 2 == 0) {
                target /= 2;
                maxDoubles --;
            }
            else
                target -= 1;
            
            moves++;
        }
        
        return moves+target-1;
    }
};