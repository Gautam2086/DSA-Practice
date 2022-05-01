class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int idx= 0;
        int mini= INT_MAX;
        int n= nums.size();
        long long sum= 0;
        //= accumulate(nums.begin(), nums.end(), 0);
        for(auto x : nums)
            sum+=x;
        
        long long currSum= 0;
        
        
        for(int i=0; i<n; i++)
        {
            currSum += nums[i];
            sum -= nums[i];
            
            int avg1= currSum == 0 ? 0 : (currSum/(i+1));
            int avg2= sum == 0 ? 0 : sum/(n-i-1);
            
            if(abs(avg1-avg2) < mini) {
                mini = abs(avg1-avg2);
                idx= i;
            }
        }
        
        return idx;
    }
};