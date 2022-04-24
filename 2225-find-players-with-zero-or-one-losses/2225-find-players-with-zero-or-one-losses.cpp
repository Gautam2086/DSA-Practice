class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        set<int> st;
        
        
        for(auto it: matches)
        {
            st.insert(it[0]);
            mp[it[1]]++;
        }
        vector<int> v2;
        
        for(auto x: mp) {
            if(x.second == 1)
                v2.push_back(x.first);
            st.erase(x.first);
        }
            
        vector<int> v1;
        for(auto x: st) {
            if(mp.find(x) == mp.end())
                v1.push_back(x);
        }
            
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        vector<vector<int>>ans;
        ans.push_back(v1);
        ans.push_back(v2);
        
        return ans;
    }
};