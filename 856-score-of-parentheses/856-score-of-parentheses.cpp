class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        int innerScore = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(innerScore);
                innerScore = 0;
            }
            else {                // inner bracket, curr bracket
                innerScore = st.top() + max(2 * innerScore, 1);
                st.pop();
            }
        }
        return innerScore;
    }
};