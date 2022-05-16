class Solution {
public:
    vector<vector<int>> dirs= {
        {-1,-1},    {-1,0},    {-1,1},
        {0,-1},                {0,1},
        {1, -1},    {1,0},     {1, 1}
    }; 
    
    bool check(int x, int y, vector<vector<int>>& grid) 
    {
        if(x>=grid.size() || y>=grid[0].size() || x<0 || y<0 || grid[x][y] == 1)
            return false;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] == 1)                         // Base Case
            return -1;
            
        int n= grid.size();
        queue<pair<int,int>> q;
        q.push({0, 0});
        int level= 0;
        
        while(!q.empty())
        {
            int s= q.size();
            while(s--)
            {
                int x= q.front().first;
                int y= q.front().second;
                q.pop();
                
                if(x==n-1 && y==n-1)
                    return level+1;
                
                for(auto dir: dirs)                // to check in all 8-directions
                {
                    int dx= x + dir[0];
                    int dy= y + dir[1];
                    
                    if(dx==x && dy==y)  continue;
                    
                    if(check(dx, dy, grid)) {
                        grid[dx][dy]= 1;
                        q.push({dx, dy});
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};