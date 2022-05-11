class Solution {
public:
    vector<char> vowels= {'a', 'e', 'i', 'o', 'u'};
    
    int helper(int n, int idx) {
        if(n == 0) {
            return 1;
        }
        if(idx >= vowels.size())
            return 0;
        
        int op1= helper(n-1, idx);
        int op2= helper(n, idx+1);
        
        return op1+op2;
    }
    
    int countVowelStrings(int n) {
        int i= 0;
        
        int ans= helper(n, i);
        
        return ans;
    }
};