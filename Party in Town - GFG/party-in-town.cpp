// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// Calc. farthest dis from all nodes 
// return minimum among them
class Solution{
public:

    void dfs(int src, vector<vector<int>> &adj, vector<bool>& vis,  vector<int>& dis) {
        
        //vis[src] = true;
        
        for(auto x: adj[src]) {
            if(!vis[x]) {
                vis[x]= true;
                dis[x]= dis[src] + 1;
                dfs(x, adj, vis, dis);
            }
        }
        return;
    }
    
    int partyHouse(int N, vector<vector<int>> &adj){
        int ans= INT_MAX;
        
        for(int i=1; i<=N; i++) 
        {
            vector<bool> vis(N+1, false);
            vector<int>  dis(N+1);
            
            if(vis[i] == false) {
                dis[i] = 0;
                vis[i] = true;
                dfs(i, adj, vis, dis);
            }
            
            int mxi= INT_MIN;
            for(int i=0; i<=N; i++) {
                mxi= max(mxi, dis[i]);
            }
            ans= min(ans, mxi); 
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends