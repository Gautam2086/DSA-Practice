// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	bool isValid(int x, int y, int n) {
	    return x>=0 && x<n && y>=0 && y<n;
	}
	double findProb(int n,int x, int y, int steps)
	{
	    int dx[8] = {1, -1, -1, 1, 2, -2, -2, 2};
        int dy[8] = {2, 2, -2, -2, 1, 1, -1, -1};
        
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        dp[x][y]= 1;
        
        while(steps--)
        {
            vector<vector<double>> next_dp(n, vector<double>(n, 0.0));
            for(int i=0; i<n; i++) 
            {
                for(int j=0; j<n; j++) 
                {
                    if(dp[i][j] != 0.0)
                    {
                        for(int k=0; k<8; k++) {
                            int newDx= i+dx[k];
                            int newDy= j+dy[k];
                            if(isValid(newDx, newDy, n)) {
                                next_dp[newDx][newDy] += ((1.0*dp[i][j])/8.0);
                            }
                        }
                    }
                }
            }
            dp= next_dp;
        }
        
        double ans= 0.0;
        for(auto i: dp) {
            for(auto j: i)
                ans += j;
        }
        return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends