class Solution {
public:
    int sum= 0;
    
    void solve(int i, int xo, vector<int>& nums) {
        
        if(i==nums.size()) {
            sum += xo;
            return;
        }
        
        solve(i+1, xo, nums);
        solve(i+1, xo^nums[i], nums);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(0, 0, nums);
        return sum;
    }
};