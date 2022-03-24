class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums.size();
        
        int inc= 1;
        int dec= 1;
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                inc= dec+1;
            }
            else if(nums[i] < nums[i-1]) {
                dec= inc+1;
            }
            // if(nums[i] == nums[i-1])       => do nothing with inc & dec, just ignore
        }
        
        return max(inc, dec);
    }
};