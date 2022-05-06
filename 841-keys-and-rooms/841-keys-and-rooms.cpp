class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int s, vector<bool>& vis) {
        
        vis[s]= true;
        
        for(auto key: graph[s])
        {
            if(!vis[key]) {
                dfs(graph, key, vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n= rooms.size();
        vector<bool> vis(n, false);
        
        dfs(rooms, 0, vis);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                return false;
            }
        }
        
        return true;
    }
};