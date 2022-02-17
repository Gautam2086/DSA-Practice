// Idea is to use Unbounded Knapsack and check all possible value by accepting and rejecting combination

class Solution {
public:
    vector<vector<int>> res;
    
    void solve(int i,int target, vector<int>& arr, vector<int>& v) {
        
        if(i == arr.size()) {
            if(target == 0) {                        // we got a combination
                res.push_back(v);                   // store combination
            }
            return;
        }
        
        // pick up the element 
        if(arr[i] <= target) {
            v.push_back(arr[i]);
            solve(i, target-arr[i], arr, v);        // Unbounded knapsack
            v.pop_back();                           // backtrack
        }
        // donot pick up the element
        solve(i+1, target, arr, v);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> v;                              // to store combinations
        solve(0, target, candidates, v);
        return res;
    }
};