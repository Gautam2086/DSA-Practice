class Solution {
public:
/*
1. Find max sum of all k length subarrays(contiguous)
*/
    double findMaxAverage(vector<int>& nums, int k) {
        double sum= 0;
        
        int i;
        for(i=0; i<k; i++) {
            sum += nums[i];
        }
        double max_sum= sum;
        
        int j= 0;
        while(i<nums.size())
        {
            sum += nums[i++];
            sum -= nums[j++];
            max_sum= max(max_sum, sum);
        }
        
        return (double)max_sum/k;
    }
};