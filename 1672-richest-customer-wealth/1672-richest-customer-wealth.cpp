class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int mx= 0;
        int r= accounts.size();
        int c= accounts[0].size();
        
        for(int i=0; i<r; i++) {
            int curr= 0;
            for(int j=0; j<c; j++) {
                curr += accounts[i][j];
            }
            mx= max(mx, curr);
        }
        return mx;
    }
};