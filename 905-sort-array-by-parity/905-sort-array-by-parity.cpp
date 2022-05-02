class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0; 
        int j=0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] % 2)
                continue;
            else {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }
};