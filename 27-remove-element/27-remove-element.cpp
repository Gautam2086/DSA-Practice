class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        unordered_map<int, int> mp;
        
        for(int x: nums) {
            mp[x]++;
            if(x == val)
                mp[x]= 0;
        }
            
        int i= 0;
        for(auto it: mp) {
            while(it.second--)
            {
                nums[i++]= it.first;
            }
        }
        
        return i;    
    }
};