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
            if(nums[i] > nums[i-1])             // inc
                inc= 0;
        }

        return inc || dec;
    }
};