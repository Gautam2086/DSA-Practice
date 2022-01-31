class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int, int>&b) {
        return (a.first>b.first) || (a.first==b.first && a.second>b.second);
    }
    
    vector<int> getStrongest(vector<int>& arr, int k) {
        
        int n= arr.size();
        sort(arr.begin(), arr.end());
        
        int tmp= (n-1)/2;
        int m= arr[tmp];
        
        vector<pair<int, int>> strong;              // diff, ele
        
        for(int i=0; i<n; i++) {
            strong.push_back( {abs(arr[i]-m), arr[i]});
        }
        
        sort(strong.begin(), strong.end(), cmp);
        
        vector<int> ans;
        
        for(int i=0; i<k; i++) {
            ans.push_back(strong[i].second);
        }
        return ans;
    }
};