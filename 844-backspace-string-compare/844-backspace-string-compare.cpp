class Solution {
public:
    // TC: O(m+n)
    // SC: O(1)
    bool backspaceCompare(string s, string t) {
        int i= s.length()-1;
        int j= t.length()-1;
        
        int sSkips= 0;
        int tSkips= 0;
        
        while(i>=0 or j>=0) 
        {
            while(i>=0)
            {
                if(s[i] == '#')
                    sSkips++;
                else if(sSkips > 0)
                    sSkips--;
                else
                    break;
                i--;
            }
            while(j>=0)
            {
                if(t[j] == '#')
                    tSkips++;
                else if(tSkips > 0)
                    tSkips--;
                else
                    break;
                j--;
            }
            
            if(i>=0 and j>=0 and s[i]!=t[j])
                return false;
            
            if((i>=0) != (j>=0))
                return false;
            
            i--;    j--;
        }
        
        return true;
    }
};