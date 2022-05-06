class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n= rooms.size();
        vector<bool> vis(n, false);
        
        queue<int> q;
        q.push(0);
        vis[0]= true;
        
        while(!q.empty())
        {
            int room= q.front();    q.pop();
            
            for(auto key: rooms[room])
            {
                if(!vis[key]) {
                    q.push(key);
                    vis[key]= true;
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(vis[i] == false) {
                return false;
            }
        }
        return true;
    }
};