class Solution {
public:
    // TC: O(m+n)
    // SC: O(m+n)
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        
        for(auto ch: s) {
            if(ch == '#' && !st1.empty())
                st1.pop();
            else if(ch != '#')
                st1.push(ch);
        }
        for(auto ch: t) {
            if(ch == '#' && !st2.empty())
                st2.pop();
            else if(ch != '#')
                st2.push(ch);
        }

        return st1==st2;
    }
};