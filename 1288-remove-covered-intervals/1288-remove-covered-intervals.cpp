class Solution {
public:
    // Brute force: O(n^2)
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int n= intervals.size();
        int ans= 0;
        
        for(int i=0; i<n; i++)
        {
            if(intervals[i][0] != -1)
            {
                for(int j=0; j<n; j++) 
                {
                    if( i!=j && intervals[j][0] != -1 && intervals[j][0]>=intervals[i][0] &&                                 intervals[j][1] <= intervals[i][1]) 
                    {
                        // intervals[j] lies in intervals[i]
                        intervals[j][0]= -1; // mark visited
                        ans++;              
                    }
                }
            }
            
        }
        return n-ans;
    }
};