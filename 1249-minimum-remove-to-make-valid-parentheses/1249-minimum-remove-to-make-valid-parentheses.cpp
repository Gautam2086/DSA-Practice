class Solution {
public:
/*
Invalid case:
1. From left to Right: if count of open < count of close 
2. From right to left: if count of close < count of open
*/
    string minRemoveToMakeValid(string s) {
     
        stack<int> st;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ')')
            {
                if(!st.empty() && s[st.top()] == '(') {
                    st.pop();
                }
                else
                {
                    s.erase(i, 1);
                    i--;
                }
            }
            else if(s[i] == '(')
                st.push(i);
        }
        
        while(!st.size() == 0) {
            s.erase(st.top(), 1);
            st.pop();
        }
        return s;
    }
};