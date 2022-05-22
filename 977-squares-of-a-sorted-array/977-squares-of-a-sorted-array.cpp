class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();
        vector<int> res(n);
        
        int lo= 0;
        int hi= n-1;
        int i= n-1;
        
        while(lo<=hi)
        {
            if(nums[lo]*nums[lo] > nums[hi]*nums[hi]) {
                res[i--]= nums[lo]*nums[lo];
                lo++;
            }
            
            else if(nums[lo]*nums[lo] <= nums[hi]*nums[hi]) {
                res[i--]= nums[hi]*nums[hi];
                hi--;
            }
        }
        
        return res;
    }
};