// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> Arr){
        
        vector<int> ans(N, 0);
        //ans[N-1]= -1;
        
        for(int i=0; i<N; i++) 
        {
            bool found= false;
            for(int j= N-1; j>i; j--) {
                if(Arr[j] < Arr[i]) {
                    found= true;
                    ans[i]= j;
                    break;
                }
            }
            if(found == false)
                ans[i]= -1;
        }
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends