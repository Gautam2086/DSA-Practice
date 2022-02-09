class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        set<vector<int>> st;
        unordered_map<int, int> mp;
        for(int x: nums)
            mp[x]++;
        
        for(int i=0; i<nums.size(); i++) {
            int x= nums[i]-k;
            mp[nums[i]]--;
            
            if(mp.find(x) != mp.end() && mp[x]>0)
            {
                //cout<<nums[i]<<" "<<x<<endl;
                vector<int> temp= {nums[i], x};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            mp[nums[i]]++;
        }
        return st.size();
    }
};