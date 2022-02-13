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
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        helper(0, nums, tmp);
        
        set<vector<int>> st;            // to avoid duplicates
        for(auto v: res) {
            sort(v.begin(), v.end());
            st.insert(v);
        }
        res.clear();
        for(auto v: st) {
            res.push_back(v);
        }
        
        return res;
    }
};