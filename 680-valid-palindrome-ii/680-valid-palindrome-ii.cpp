class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
    
        while(i<=j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true; 
    }
    
    bool validPalindrome(string s) {
        int lo= 0, hi= s.length()-1;
        
        while(lo<=hi)
        {
            if(s[lo] != s[hi]) {
                return isPalindrome(s, lo, hi-1) || isPalindrome(s, lo+1, hi);
                // skip curr char from left or from right -> delete at most one character
            }
            else {
                lo++;
                hi--;
            }
        }
        return true;
    }
};