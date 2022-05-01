class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string> st;
        
        for(auto str: logs) 
        {
            if(str == "../" && !st.empty())
                st.pop();
            
            else if(str == "./")
                continue;
            
            else if(str != "../")
                st.push(str);   
        }
        
        return st.size();
    }
};