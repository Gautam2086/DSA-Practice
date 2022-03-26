class Solution {
public:
/*
1. Arrray is sorted
2. Runtime complexity of O(log n) is asked
3. That's why Binary Search is used
*/
    int search(vector<int>& nums, int target) {
        
        int lo= 0;                          // low pointer
        int hi= nums.size()-1;              // high pointer
        int ans= 0;
        
        while(lo<=hi)
        {               
            int mid= lo+(hi-lo)/2;          // mid pointer
            
            if(nums[mid] == target)         // target is found
                return mid;                 // this is our target's index
            
            if(nums[mid] < target) {        // search in right side 
                lo= mid+1;
            }   
            else if(nums[mid] > target) {   // search in left side
                hi= mid-1;
            }
        }
        return -1;                          // if we din't get idx in above loop 
    }                                       // that means target is not present
};