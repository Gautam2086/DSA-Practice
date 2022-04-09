class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        
        for(auto n: nums) {
            mp[n]++;
        }
        
        for(auto x: mp) {
            pq.push({x.second, x.first});
        }
        
        int i=0; 
        while(i<k) {
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        
        return ans;
    }
};