class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size())
            k= k % nums.size();
        
        
        reverse(nums.begin(), nums.end()-k);      // sort till nums.end()-k-1
        reverse(nums.end()-k, nums.end());        // sort till nums.end()-1
        
        reverse(nums.begin(), nums.end());
    }
};