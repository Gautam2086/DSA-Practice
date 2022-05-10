class Solution {
public:
    vector<vector<int>> res;
    
    void helper(int i, int target, vector<int>& arr, vector<int>& v) {
        if(i==arr.size())
        {
            if(target == 0)
                res.push_back(v);
            return;
        }
        
        // pickup element
        if(arr[i] <= target) {
            v.push_back(arr[i]);
            helper(i, target-arr[i], arr, v);
            v.pop_back();
        }
        // Ignore element
        
        helper(i+1, target, arr, v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        
        helper(0, target, candidates, v);
        return res;
    }
};