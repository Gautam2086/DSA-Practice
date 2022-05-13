class Solution {
public:
    vector<vector<int>> res;
    
    void helper(int i, vector<int>& nums) {
        
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for(int j=i; j<nums.size(); j++) {
            swap(nums[i], nums[j]);
            helper(i+1, nums);
            swap(nums[i], nums[j]);             // Backtrack
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        helper(0, nums);
        
        return res;
    }
};