class Solution {
public:
/*
- Build the string of length k, which consists of letter 'a' (lexicographically smallest       string).
- Greedily(Increment) changing the letters from the right to left until it's value won't       reach the target. to get the lexicographically smallest string.

TC: O(n)
SC: O(1)
*/
    string getSmallestString(int n, int k) {
        
        string s(n, 'a');
        k= k-n;
        
        int i= n-1;
        while(k>0)
        {
            int temp= min(k, 25);
            
            s[i] += temp;
            
            k= k-temp;
            i--;
        }
        
        return s;
    }
};