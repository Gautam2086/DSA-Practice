// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        
        int ans= 0;
        unordered_map<int, int> xmap;
        unordered_map<int, int> ymap;
        unordered_map<string, int> xymap;
        
        for(int i=0; i<N; i++) {
            int x= X[i];
            int y= Y[i];
            
            string xy= "" +to_string(x) + '*' + to_string(y);
            
            int xfreq= xmap[x];
            int yfreq= ymap[y];
            int xyfreq= xymap[xy];
            
            ans += xfreq + yfreq - 2*xyfreq;
            xmap[x]++;
            ymap[y]++;
            xymap[xy]++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends