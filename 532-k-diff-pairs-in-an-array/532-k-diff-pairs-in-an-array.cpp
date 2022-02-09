class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        int ans = 0;
        for(auto x: nums)
            m[x]++;
        
        for(auto x: m)
        {
            if(k == 0)
            {
                if(x.second > 1)
                    ans++;
            }    
            else
            {
                m[x.first]--;
                if(m.find(x.first - k) != m.end())
                  ans++;
                m[x.first]++;
            }
        }
        
        return ans;
    }
};