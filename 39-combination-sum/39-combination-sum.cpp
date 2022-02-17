// Idea is to use Unbounded Knapsack and check all possible value by accepting and rejecting combination

class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int>& arr, int n, int w, vector<int> v) {
        if(w==0) return res.push_back(v);
        if(n==0) return;
        solve(arr, n-1, w, v);
        if(arr[n-1] <= w) {
            v.push_back(arr[n-1]);
            solve(arr, n, w-arr[n-1], v);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> v;
        solve(candidates, candidates.size(), target, v);
        return res;
    }
};