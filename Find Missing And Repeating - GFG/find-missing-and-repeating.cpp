// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int repeat= 0;
        int miss= 0;
        
        unordered_map<int, int> mp;
        
        for(int i=1; i<=n; i++) {
            mp[i]++;
        }
        
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
        } 
        for(auto it: mp) {
            if(it.second < 2)
                miss= it.first;
            if(it.second > 2)
                repeat= it.first;
        }
        int *res= new int[2];
        res[0]= repeat;
        res[1]= miss;
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends