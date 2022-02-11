// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        string res= "";
        int n= s.length();
        
        for(int i=0; i<n; i++)
        {
            string tmp= "";
            while(i<n && s[i]== '0')
                i++;
            while(i<n && s[i]!= '.')
                tmp += s[i++];
                
            if(tmp.size()==0)
                tmp = '0';
            
            res += i<n ? tmp+'.' : tmp;
        }
        //res= res.substr(0, res.length()-1);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends