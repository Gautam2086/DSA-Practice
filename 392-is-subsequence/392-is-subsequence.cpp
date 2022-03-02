class Solution {
public:
    
    
    bool helper(string& s, string& t, int i, int j) {
        if(i<0)
            return true;
        if(j<0) {
            return false; 
        }
        
        if(s[i] == t[j]) {
            return helper(s, t, i-1, j-1);
        }
        else {
            return helper(s, t, i, j-1);
        }
        
    }
    
    bool isSubsequence(string s, string t) {
        if(s.length() > t.length())
            return false;
        if(s.size() == 0 )
            return true;
        
        return helper(s, t, s.length()-1, t.length()-1);
    }
};