class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr= nums;
        sort(arr.begin(), arr.end());
        //vector<int> diff;
        
        int idx1= INT_MAX;
        int idx2= INT_MIN;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != arr[i]) {
                idx1= min(idx1, i);
                idx2= max(idx2, i);
            }
        }
    
        if(idx1 == INT_MAX || idx2 == INT_MIN)
            return 0;
        return idx2-idx1+1;
    }
};