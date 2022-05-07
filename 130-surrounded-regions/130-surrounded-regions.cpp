class Solution {
public:
    vector<vector<int>> dirs= {
                {-1,0},
        {0,-1},        {0,1},
                {1,0}
    };
    
    bool isValid(int i, int j, int n, int m, vector<vector<char>>& board) {
        if(i>=0 && i<n && j>=0 && j<m && board[i][j] == 'O') {
            return true;
        }
        return false;
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board) {
        
        board[i][j]= 'B';
        
        for(auto dir: dirs) {
            int nx= i + dir[0];
            int ny= j + dir[1];
            
            if(isValid(nx, ny, n, m, board))
                dfs(nx, ny, n, m, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i*j == 0 || i == n-1 || j == m-1) {
                    if(board[i][j] == 'O')
                        dfs(i, j, n, m, board);
                }
            }
        }
    
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'B')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};