class Solution {
public:
    // Optimised approach -> TC: O(n*logn), SC: O(1)
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int ans= 0;
        int left= -1, right= -1;
        
        for(auto v: intervals)
        {
            if(v[0] > left && v[1] > right) {           // if not satisfying covered condition
                left= v[0];
                ans++;  
            }
            right= max(right, v[1]);    
        }
        
        return ans;
    }
};