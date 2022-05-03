class Solution {
public:
    // TC: O(n)
    // SC: O(1)
    int findUnsortedSubarray(vector<int>& nums) {
        int n= nums.size();
        int mini= INT_MAX;
        int maxi= INT_MIN;
        
        for(int i=0; i<n-1; i++) {
            if(nums[i] > nums[i+1])
                mini= min(mini, nums[i+1]);
        }
        
        for(int i=n-1; i>0; i--) {
            if(nums[i] < nums[i-1])
                maxi= max(maxi, nums[i-1]);
        }
        
        int l= 0, r= 0;
        for(int i=0; i<n; i++) {
            if(nums[i] > mini) {
                l= i;
                break ; 
            }
                
        }
        for(int i=n-1; i>=0; i--) {
            if(nums[i] < maxi) {
                r= i;
                break ;
            } 
        }
        
        return r-l>0 ? r-l+1 : 0;
    }
};