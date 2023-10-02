class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int alice= 0;
        int bob= 0;
        
        for(int i=0; i<colors.length(); i++)
        {
            if(colors[i]== 'A' && colors[i+1]== 'A' && colors[i+2]== 'A') {
                alice++;
            }
            else if(colors[i]== 'B' && colors[i+1]== 'B' && colors[i+2]== 'B') {
                bob++;
            }
        }

        return alice>bob;
    }
};