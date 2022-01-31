class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n= code.size();
        vector<int> ans(n, 0);
        
        if(k>0) 
        {
            for(int i=0; i<n; i++) {
                for(int j=1; j<=k; j++)             // Go k steps forward 
                {
                    int num= code[(i+j)%n];
                    ans[i] += num;
                }
            }
            return ans;
        }
        
        else if(k<0)
        {
            for(int i=0; i<n; i++) {
                for(int j=1; j<=-1*k; j++)          // Go k steps back 
                {
                    int num= code[(i-j+n)%n];
                    ans[i] += num;
                }
            }
            return ans;
        }
        
        else {                                      // if k==0
            return ans;
        }
    }
};