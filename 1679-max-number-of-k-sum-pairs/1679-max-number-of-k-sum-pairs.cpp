class Solution {
public:
    /*
     1,3,3,3,4
     1,2,3,4
    */
    int maxOperations(vector<int>& nums, int k) {
        
        int ans= 0;
        sort(nums.begin(), nums.end());
        int i= 0;
        int j= nums.size()-1;
        
        while(i<j)
        {
            if(nums[i] + nums[j] == k) {
                ans++;
                i++;    j--;
            }
            else if(nums[i] + nums[j] < k) {
                i++;
            }
            else if(nums[i] + nums[j] > k) {
                j--;
            }
        }
        
        return ans;
    }
};