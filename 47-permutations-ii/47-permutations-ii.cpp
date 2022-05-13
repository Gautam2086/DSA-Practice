class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> s;
    
    void helper(int i, vector<int>& nums) {
        
        if(i == nums.size()) {
            s.insert(nums);
            return;
        }
        
        for(int j=i; j<nums.size(); j++) {
            swap(nums[i], nums[j]);
            helper(i+1, nums);
            swap(nums[i], nums[j]);             // Backtrack
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(0, nums);
        
        for(auto v: s) {
            res.push_back(v);
        }
        return res;
    }
};