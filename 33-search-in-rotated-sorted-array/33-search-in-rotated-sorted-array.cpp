class Solution {
public:
/*
    [4,5,6,7,0,1,2]
           P            [P = pivot index]
    
- Find pivot idx and 
- apply binary search on left half array of pivot idx
- apply binary search on right half array of pivot idx
- return any ans which os not -1

*/
    int pivotIdx(vector<int>& nums)
    {
        int lo= 0;
        int hi= nums.size()-1;
        
        if(nums[lo] < nums[hi]) {
            return 0;                       // array is not rotated
        }
        
        int pivot= -1;
        
        while(lo<=hi)
        {
            int pivot= lo+ (hi-lo)/2;
            
            if(nums[pivot] > nums[pivot+1])
                return pivot;
            else
            {
                if(nums[pivot] < nums[lo])
                    hi= pivot-1;
                else
                    lo= pivot+1;
            }
        }
        return 0;
    }
    
    int binarySearch(vector<int>& nums, int lo, int hi, int target)
    {
        int n=nums.size();
        
        while(lo<=hi)
        {
            int mid= lo+ (hi-lo)/2 ;
            
            if(nums[mid] == target)
                return mid;
            if(target < nums[mid])
                hi= mid-1;
            else
                lo=mid+1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int n= nums.size();
        if(n==1)
            return nums[0]==target ? 0 : -1;
        
        int pivot_idx= pivotIdx(nums);
        
        int ans1= binarySearch(nums, 0, pivot_idx, target);
        int ans2= binarySearch(nums, pivot_idx+1, n-1, target);
        
        if(ans1 !=-1)
            return ans1;
        else if(ans2 !=-1)
            return ans2;
        else
            return -1;
    }
};