// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(int s, int V, vector<int> adj[], vector<bool>& vis) {
        queue<pair<int,int>> q;         // {node, parent}
        vis[s]= true;
        
        q.push({s, -1});
        while(!q.empty())
        {
            auto it= q.front(); q.pop();
            int node= it.first;
            int par= it.second;
            
            for(auto x: adj[node]){
                if(!vis[x]) {
                    vis[x]= true;
                    q.push({x, node});
                }
                else if(par != x)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V+1, false);
        for(int i=0; i<V; i++) {
            if(!vis[i])
                if(check(i, V, adj, vis))   return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends