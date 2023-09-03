class Solution {
public:
    int t[101][101];
    int M, N;
    int solve(int i, int j) 
    {
        if(i == M-1 && j == N-1)
            return 1;
        if(i >= M || j > N)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];

        int op1 = solve(i+1, j);
        int op2 = solve(i, j+1);

        return t[i][j]= op1+op2;
    }

    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        memset(t, -1, sizeof(t));
        
        return solve(0, 0);
    }
};