class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n= nums.size();
        vector<string> res;
        
        for(int i=0; i<n;)
        {
            int st= i;
            int end= i;
            
            while(end < n-1 && nums[end+1] == nums[end]+1)      // check if nums are consecutive
                end++;
            
            if(end > st)
                res.push_back( to_string(nums[st]) + "->" + to_string(nums[end]) );
                // "a->b" if a != b
            else
                res.push_back( to_string(nums[st]) );
                // "a" if a == b
            i= end+1;       
        }
        
        return res;
    }
};