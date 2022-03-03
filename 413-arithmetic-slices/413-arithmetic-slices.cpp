class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        if(nums.size() < 3)
            return 0;
        
        int res= 0;
        int n= nums.size();
        
        for(int i=0; i<=n-3; i++)
        {
            int diff= nums[i+1]-nums[i];
            
            for(int j=i+2; j<n; j++)
            {
                if(nums[j]-nums[j-1] == diff)
                    res++;
                else
                    break;
            }
        }
        
        return res;
    }
};