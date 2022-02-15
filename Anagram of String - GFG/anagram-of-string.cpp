// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
    int ans= 0;
    vector<int> freq(26, 0);
    
    for(auto ch: str1) {
        freq[ch-'a']++;
    }
    
    for(auto ch: str2) {
        if(freq[ch-'a'] > 0)
            freq[ch-'a']--;
        else
            ans++;
    }
    for(auto i: freq)
        ans+= i;
        
    return ans;
}