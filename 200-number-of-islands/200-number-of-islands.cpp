class Solution {
public:
    
    void dfs(vector<vector<char>>& arr, int i, int j, int m, int n) {
  
      if(i<0 || i>=m || j<0 || j>=n || arr[i][j] != '1')
        return;

      arr[i][j]= '2';            // Mark visited

      dfs(arr, i+1, j, m, n);
      dfs(arr, i, j+1, m, n);
      dfs(arr, i-1, j, m, n);
      dfs(arr, i, j-1, m, n);

    }
    
    int numIslands(vector<vector<char>>& grid) {
        
      vector<vector<char>> arr= grid;
      int m= arr.size();     // rows
      int n= arr[0].size();  // cols

      int islands= 0;

      for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
          if(arr[i][j] == '1')
          {
            dfs(arr, i, j, m, n);
            islands++;
          }
        }
      }

      return islands; 
    }
};