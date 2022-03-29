class Solution {
public:
/*
Negative Marking technique:

- For example, if the input array is [1, 3, 3, 2], then for 1, flip the number at index 1,   making the array [1,-3,3,2]
- Next, for -3 flip the number at index 3, making the array [1,-3,3,-2]
- Finally, when we reach the second 3, we'll notice that nums[3] is already negative,         indicating that 3 has been seen before and hence is the duplicate number.    

TC: O(n)
SC: O(1)
*/
    
    int findDuplicate(vector<int>& nums) {
        int duplicate= -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[abs(nums[i])] < 0) {
                duplicate= abs(nums[i]);
                break;
            }
            
            nums[abs(nums[i])] *= -1;           // mark visited num as -ve
        }
        
        for(auto num: nums) {                   // Restore original nums array
            num= abs(num);
        }
        
        return duplicate;
    }
};