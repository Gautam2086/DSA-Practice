class Solution {
public:
    bool canReach(vector<vector<int>>& heights, int m, int n, int x, int y, int minDiff,                                   vector<vector<bool>>& visited)
    {
        if(x==m-1 && y==n-1)    return true;
        if(visited[x][y] == 1)  return false;
        
        visited[x][y]= true;
        
        if (x - 1 >= 0 && abs(heights[x][y] - heights[x - 1][y]) <= minDiff)
            if (canReach(heights, m, n, x - 1, y, minDiff, visited)) return true;
        
        if (y + 1 < n &&  abs(heights[x][y] - heights[x][y + 1]) <= minDiff) 
            if (canReach(heights, m, n, x, y + 1, minDiff, visited)) return true;
        
        if (x + 1 < m &&  abs(heights[x][y] - heights[x + 1][y]) <= minDiff) 
            if (canReach(heights, m, n, x + 1, y, minDiff, visited)) return true;
        
        if (y - 1 >= 0 && abs(heights[x][y] - heights[x][y - 1]) <= minDiff) 
            if (canReach(heights, m, n, x, y - 1, minDiff, visited)) return true;

        return false;
    }
    bool isValid(int mid, vector<vector<int>>& heights, int m, int n) {
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        return canReach(heights, m, n, 0, 0, mid, vis);
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m= heights.size();                  // rows 
        int n= heights[0].size();               // cols
        int lo= 0;
        int hi= 1000001;
        int ans= 0;
        
        while(lo<=hi)
        {
            int mid= lo+(hi-lo)/2;
            
            if(isValid(mid, heights, m, n))
                hi= mid-1, ans= mid;
            else
                lo= mid+1;
        }
        return ans;
    }
};