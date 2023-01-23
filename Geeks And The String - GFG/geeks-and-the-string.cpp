//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        int n= s.length();
        stack<char> st;
        
        for(int i=0; i<n; i++) {
            char ch= s[i];
            
            if(!st.empty() && ch == st.top())
            {
                while(!st.empty() && ch == st.top()) {
                    st.pop();
                }
            }
            else
                st.push(ch);
        }
        
        string res= "";
        while(!st.empty()) {
            res += st.top();    
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        if(res == "")
            return "-1";
            
        
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends