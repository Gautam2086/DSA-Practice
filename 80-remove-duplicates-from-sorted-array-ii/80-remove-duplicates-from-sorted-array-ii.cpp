class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums.size();
        
        map<int, int> mp;
        for(int x: nums) {
            mp[x]++;
            if(mp[x] > 2)
                mp[x]--;
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