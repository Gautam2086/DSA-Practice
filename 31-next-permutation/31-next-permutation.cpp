class Solution {
public:
    /* Algorithm
    1. iterate array, find index1 at which a[i]< a[i+1]
    2. again iterate and find value(index2) that is just greater than value at index1
    3. swap(index1,index2)
    4. reverse(index1+1-> last)
    */
    
    void nextPermutation(vector<int>& nums) {
        
        int n= nums.size();
        int i,j;
        for(i=n-2; i>=0; i--){
            if(nums[i]< nums[i+1])              // Inflation pint
                break;            
        }
        
        if(i<0){                                //if array is in descedning order already
            reverse(nums.begin(),nums.end());   //like: 5 4 3 2 1
        }
        
        else
        {
            for(j=n-1; j>i; j--){
                if(nums[j]> nums[i])
                    break;
            }
            swap(nums[i],nums[j]);
            sort(nums.begin()+i+1,nums.end());  // Sort remaining array
        }
    }
};