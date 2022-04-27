class Solution {
public:
    bool isBalanced(string s) {
        int count= 0;
        for(char ch: s) {
            if(ch == '(')
                count++;
            else if(ch == ')')
                count--;
            if(count<0)
                return false;
        }
        return count==0;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> ans;
        map<string, bool> vis;
        queue<string> q;
        q.push(s);
        int found= 0;
        
        while(!q.empty())
        {
            string u= q.front();  q.pop();
            if(vis[u] == true)  continue;
            
            vis[u]= true;
            if(isBalanced(u) == true)
                found= 1, ans.push_back(u);
            if(found==1)
                continue;
            
            for(int i=0; i<u.size(); i++) {
                if(u[i] == '(' or u[i] == ')')
                {
                    string v= u.substr(0, i) + u.substr(i+1, u.size());
                    q.push(v);
                }
            }   
        }
        return ans;
    }
};