class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> v(n, vector<int> (n, 0));
        
        int top= 0;
        int down= n-1;
        int left= 0;
        int right= n-1;
        int index= 1;
        
        while(left<=right && top<=down)
        {
            for(int j=left; j<=right; j++) {            // Column is changing
                v[top][j]= index++;
            }
            top++;
            
            for(int i=top; i<=down; i++) {              // Row is changing
                v[i][right]= index++;
            }
            right--;
            
            for(int j=right; j>=left; j--) {            // Column is changing
                v[down][j]= index++;
            }
            down--;
            
            for(int i=down; i>=top; i--) {              // Row is changing
                v[i][left]= index++;
            }
            left++;
        }
        
        return v;
    }
};