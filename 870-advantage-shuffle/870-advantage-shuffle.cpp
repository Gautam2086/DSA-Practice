class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        multiset<int> ms;
        for(auto x: nums1) {
            ms.insert(x);
        }
        
        sort(nums1.begin(), nums1.end());
        
        vector<int> ans(nums1.size(), 0);
        
        for(int i=0; i<nums2.size(); i++) {
            
            int target= nums2[i];
            auto it= ms.upper_bound(target);
            
            if(it != ms.end())
                ans[i]= *it;
            
            else {
                it= ms.begin();
                ans[i]= *it;
            }
            
            ms.erase(it);
        }
        
        return ans;
    }
};