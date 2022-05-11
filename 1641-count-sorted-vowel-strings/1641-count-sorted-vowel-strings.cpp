class Solution {
public:
    vector<char> vowels= {'a', 'e', 'i', 'o', 'u'};
    int ans= 0;
    
    void helper(int n, int idx) {
        if(n == 0) {
            ans++;
            return;
        }
        if(idx >= vowels.size())
            return;
        
        helper(n-1, idx);
        helper(n, idx+1);
        
        return;
    }
    
    int countVowelStrings(int n) {
        int i= 0;
        helper(n, i);
        
        return ans;
    }
};