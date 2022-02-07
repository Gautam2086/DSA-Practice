/* hash table and set O(N^2)
Intution : We take a unorederd map and then calculate 2 sum of all the possiblities of i and j pair and store it in the map besides there indexes and then we run a loop and for every i and j we do target - arr[i]-arr[j] and then try to find it in the map if it exists that means this is a possible answer qudraplet.
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        int n= nums.size();
        if(n<4) return ans;
        sort(nums.begin(), nums.end());
        unordered_map<int,vector<pair<int,int>>> mp;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                mp[nums[i]+nums[j]].push_back({i,j});//making 2 sum map
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(i>0 and nums[i] == nums[i-1])  continue;
            for(int j=i+1; j<n; j++)
            {
                if(j>i+1 and nums[j] == nums[j-1])  continue;
                int sum= target - nums[i] - nums[j];
                if(mp.find(sum) != mp.end())
                {
                    for(auto it : mp[sum])
                    {
                        int k=it.first;
                        int l=it.second;
                        if(k>j)
                        {
                            if(!ans.empty() && ans.back()[0]==nums[i] && ans.back()                                             [1]==nums[j] && ans.back()[2]==nums[k] && ans.back()[3] == nums[l]) 
                                continue;
                            vector<int> temp= {nums[i],nums[j],nums[k],nums[l]};
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};