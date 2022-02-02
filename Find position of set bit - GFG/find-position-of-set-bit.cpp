// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        int bits= __builtin_popcount(N);
        
        if(bits > 1 || bits < 1)
            return -1;
            
        int count= 0;
        int i= 1;
        
        while(N!=0)
        {
            if(N&1 == 1) {
                count= i;
            }
            
            N= N>>1;
            i++;
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends