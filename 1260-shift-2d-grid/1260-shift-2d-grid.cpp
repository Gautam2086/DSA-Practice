class Solution {
public:
/*
Approach: 
- Take new matrix
- take each row, col from given grid
- convert it into idx in 1-d array
- shift ele to idx + k units
- cnvert newIdx back to 2d array matrix ie new row and col
- update new matrix accordingly
*/
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n= grid[0].size();
        
        vector<vector<int>> v(m, vector<int>(n, 0));     // new 2D array
        
        for(int r=0; r<m; r++) {
            for(int c= 0; c<n; c++) {
                
                int newIdx= ((r*n + c) + k) % (m*n);     // convert (row,col) to 1-D array idx
                int newR= newIdx/n;                      // convert newIdx to 2-D array idx
                int newC= newIdx%n;
                
                v[newR][newC]= grid[r][c];               // shift values to new co-ordinates
            }
        }
        return v;
    }
};