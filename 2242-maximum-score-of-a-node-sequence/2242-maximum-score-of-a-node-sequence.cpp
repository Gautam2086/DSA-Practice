class Solution {
public:
    
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        
        int n= scores.size();
        int ans= -1;
        vector<vector<int>> adj(n);
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        auto mycmp= [&scores](const int p1, int p2) { return scores[p1]>scores[p2]; };
        
        for(int i=0; i<n; i++)
            sort(adj[i].begin(), adj[i].end(), mycmp);
        
        
        for(int k=0; k<edges.size(); k++)
        {
            int u= edges[k][0];
            int v= edges[k][1];
            
            int least= scores[u] + scores[v];
            for(int i=0; i<min(3, (int)adj[u].size()); i++) 
            {
                int x= adj[u][i];
                if(x == v)    continue;                         // selected node should not be same
                
                for(int j=0; j<min(3, (int)adj[v].size()); j++) 
                {
                    int y= adj[v][j];
                    if(y == u || y == x)    continue;           // selected node should not be same
                    
                    ans= max(ans, least+scores[x]+scores[y]);
                }
            }
        }
        return ans;
    }
};

//auto cmp= [](const pair<int,int>&p1, pair<int,int>&p2) {return p1.second<p2.second;};