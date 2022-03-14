class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string res;
        
        for(int i = 0;  i<path.size(); i++)
        {
            if(path[i] == '/')    
                continue;
            
            string temp;
            
            while(i < path.size() && path[i] != '/') {  // Extract string between "/__/"
                temp += path[i++];
            }
            
            if(temp == ".")
                continue;
            
            else if(temp == "..") {     // means we have to go to previous parent directory
                if(!st.empty())
                    st.pop();
            }
            
            else                        // if temp == "string"
                st.push(temp);
        }
        
        while(!st.empty()) 
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};