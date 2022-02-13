class Solution {
public:
    vector<vector<int>> res;
    
    void helper(int i, vector<int>& nums, vector<int>& tmp) 
    {
        if(i==nums.size()) {
            res.push_back(tmp);
            return;
        }
        
        helper(i+1, nums, tmp);
        tmp.push_back(nums[i]);
        helper(i+1, nums, tmp);
        tmp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> tmp;
        helper(0, nums, tmp);
        
        return res;
    }
};