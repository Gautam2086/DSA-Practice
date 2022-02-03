/*
Approach: 2Pointer approach without set
TC: O(n*n)
SC: O(1)
1. a+b+c = 0
2. select each num as a in array 
3. now using two pointer approach find b,c such that b+c = -(a)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n= nums.size();
        if(n<3)     return {};
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;    
        
        for(int i=0; i<n-2; i++)                    // a can be from 1 to 3rd last num
        {
            if(i==0 || nums[i] !=nums[i-1])         // to avoid duplicates 
            {
                int lo= i+1, hi=n-1, sum= 0-nums[i];
                while(lo<hi)
                {
                    
                    if(nums[lo] + nums[hi] == sum) {
                        vector<int> temp= {nums[i], nums[lo], nums[hi]};
                        res.push_back(temp);
                        
                        while(lo < hi && nums[lo] == nums[lo+1])        // to avoid duplicates
                            lo++;
                        while(lo < hi && nums[hi] == nums[hi-1])
                            hi--;
                        
                        lo++;   hi--;
                    }
                    
                    else if(nums[lo] + nums[hi] < sum)  lo++;
                    else hi--;     
                }
            }
        }
        return res;
    }
};