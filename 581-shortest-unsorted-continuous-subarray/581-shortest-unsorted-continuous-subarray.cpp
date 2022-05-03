class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr= nums;
        sort(arr.begin(), arr.end());
        vector<int> diff;
        
        for(int i=0; i<nums.size(); i++) {
            diff.push_back(abs(nums[i]-arr[i]));
        }
        int idx1= INT_MAX;
        int idx2= INT_MIN;
        
        for(int i=0; i<diff.size(); i++) {
            if(diff[i] != 0) {
                idx1= min(idx1, i);
                idx2= max(idx2, i);
            }
        }
    
        if(idx1 == INT_MAX || idx2 == INT_MIN)
            return 0;
        return idx2-idx1+1;
    }
};