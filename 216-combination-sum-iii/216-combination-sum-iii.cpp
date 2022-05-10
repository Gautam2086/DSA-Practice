class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int k, int n, vector<int>& v, int st) {
        
        if(n == 0 && v.size() == k) {
            ans.push_back(v);
            return;
        }
        if(n <= 0 || v.size() >= k)
            return;
        
        for(int i=st; i<=9; i++) {
            v.push_back(i);
            helper(k, n-i, v, i+1);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        helper(k, n, v, 1);
        
        return ans;
    }
};