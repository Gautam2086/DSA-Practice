class Solution {
public:
    // TC: O(n)
    // SC: O(n)
    string smallestSubsequence(string s) {
        
        vector<int> lastIndex(26, 0);               // store last index of all letters
        for (int i = 0; i < s.length(); i++){
            lastIndex[s[i] - 'a'] = i; 
        }
        
        vector<bool> seen(26, false);               // track if char is taken or not
        stack<char> st;                             // store the smallest lexico string
        
        for (int i = 0; i < s.size(); i++)
        {
            int curr = s[i] - 'a';
            
            if (seen[curr] == true){
                 continue;
            }
            
            while(st.size() > 0 && st.top() > s[i] && i < lastIndex[st.top() - 'a']){
                seen[st.top() - 'a'] = false; 
                st.pop();
            }
            
            st.push(s[i]); 
            seen[curr] = true; 
        }
        
        string res = "";
        
        while (st.size() > 0){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};