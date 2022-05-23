class Solution {
public:
    int dp[601][101][101]= {};
    int helper(vector<pair<int, int>>& v, int idx, int ones, int zeros) 
    {
        // BASE CASES
        // 1. if we have reched the end of our array then we dont have any options left
        // 2. if we have no available zeros or ones to use then also we dont have any options               left
        if(idx == v.size() or (ones == 0 and zeros == 0))
            return 0;
        
        if(dp[idx][ones][zeros] != -1)
            return dp[idx][ones][zeros];
        
        if(v[idx].first > ones or v[idx].second > zeros)
            return helper(v, idx+1, ones, zeros);
        
        // now at this point we have two paths to explore, we want to know that what is the              answer going to be if i 
        // use this pair 
        // or if i leave this pair
        int include = 1 + helper(v, idx+1, ones-v[idx].first, zeros-v[idx].second);
        int exclude = 0 + helper(v, idx+1, ones, zeros);
        
        // now since we know the our answers for both of our decisions then we can choose the            one which yeilds the max result
        return dp[idx][ones][zeros]= max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp ,-1, sizeof dp);
        // create vector pair to store no. of zeros & ones or ith string
        vector<pair<int, int>> v;
        for(auto i: strs) {
            int one= 0, zero= 0;
            
            for(auto j: i) {
                if(j == '1')
                    one++;
                else
                    zero++;
            }
            v.push_back({one, zero});
        }
        
        int ans= helper(v, 0, n, m);
        
        return ans;
    }
};