class Solution {
public:
/*
Calculate Relative Cost(RC) for each person:

- RC means the profit (saving) that we'll get by flying person to city A over city B
    - if RC= +ve that means we make profit of x val if we choose A instead of B
    - if RC= -ve that means we make loss of x val if we choose A instead of B
    
- Sort these RC in descending order (ie get max RC at front)
- Send first n persons in RC (sorted) list to city A
- Send left n students to city B 
*/

    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int minCost= 0;
        int n= costs.size();
        vector<pair<int,int>> rc;                       // Relative cost array
        
        for(int i=0; i<n; i++) {
            rc.push_back({costs[i][1]-costs[i][0], i});
        }
        
        sort(rc.begin(), rc.end(), greater());
        //sort(rc.begin(), rc.end(), myCmp);
        
        for(auto x: rc) {
            cout<<x.first<<" ";
        }
        
        for(int i=0; i<n/2; i++) {
            minCost += costs[rc[i].second][0];
        }
        for(int i=n/2; i<n; i++) {
            minCost += costs[rc[i].second][1];
        }
        
        return minCost;
    }
};