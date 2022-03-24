class Solution {
public:
    //bool 
    bool isMonotonic(vector<int>& nums) {
        int monotonic= 1;
        int inc= 1;
        int dec= 1;
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < nums[i-1])              // dec
                dec= 0;
            else if(nums[i] > nums[i-1])         // inc
                inc= 0;       
        }
        if(inc == 0 && dec == 0)
            return false;
        return true;
    }
};