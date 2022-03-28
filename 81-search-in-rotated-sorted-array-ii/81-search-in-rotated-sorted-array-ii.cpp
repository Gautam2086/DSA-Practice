class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int lo= 0, hi =nums.size()-1;
        
        while(lo<=hi)
        {
            int mid= lo+(hi-lo) /2;
            
            if(nums[mid] == target)
                return true;
        
            if(nums[lo]  < nums[mid])       // left part is sorted 
            {
                if(target < nums[lo] || target > nums[mid]){
                                            // target is out of the left part boundary
                    lo = mid +1;
                }
                else{                       // target lies within this left part
                    hi = mid -1;
                }
            }       
            else if(nums[lo]  > nums[mid])  // right part is sorted
            {                                   
                if(target < nums[mid] || target > nums[hi])
                    hi=mid-1;
                else                        // target lies within the right part boundaries
                    lo= mid+1;                     
            }
            
            else {                          // duplicates
                lo++;                       // => O(n) 111111112
            }     
        }
         return false;
    }
};