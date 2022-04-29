class Solution {
public:
    bool checkPartite(vector<vector<int>>& graph, int src, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        color[src] = 1;
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front(); q.pop();
            for(auto x: adj[node]) {
                if(color[x] != -1) {
                    if(color[x] == color[node])
                        return false;
                }
                else {
                    color[x] = 1-color[node];
                    q.push(x);
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<vector<int>> adj(n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            } 
        }
        vector<int> color(n, -1);   // 0 or 1
        
        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(!checkPartite(graph, i, adj, color))
                    return false;
            }
        }
        return true;
    }
};