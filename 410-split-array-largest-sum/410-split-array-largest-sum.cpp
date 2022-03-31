class Solution {
public:
/*
- Apply Binary Search on Answer

->the idea is that min max sum will lie in the range (max(nums[i]),sum(nums[i])) for(i=0 to n)
->every time we find avg of this range and see how many intervals' sum exceed the avg
->if there are more than "m" intervals, then we need to increase the bar becoz many intervals are demanding to get separated
->if they are less than "m", then we need to lower the bar becoz very few intervals are willing to get separated
->we will keep doing this until if reach a postn when exactly "m" intervals will get separated
->at this point we will obvsly have lower bar=upper bar
*/
    bool isValid(vector<int>& nums, int mid, int m) {
        int subArray= 1;
        int sum= 0;
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
        
            if(sum > mid) {
                subArray++;
                sum= nums[i];
            }
        }
        return subArray<=m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int mx= *max_element(nums.begin(), nums.end());
        int sum= accumulate(nums.begin(), nums.end(), 0);
        
        if(m == nums.size())    // Edge case
            return mx;
        
        int lo= mx;
        int hi= sum;
        int ans= -1;
        
        while(lo<=hi)
        {
            int mid= lo+ (hi-lo)/2;
            
            if(isValid(nums, mid, m) == true) {
                // if m subbarrays se kum subarrays lage, then check for lesser val of sum
                ans= mid;
                hi= mid-1;
            }
            else {              // if m subbarrays se zada subarrays lage
                lo= mid+1;      // then increase sum
            }
        }
        
        return ans;
    }
};