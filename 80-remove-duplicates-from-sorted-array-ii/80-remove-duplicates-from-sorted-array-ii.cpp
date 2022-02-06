/*Just insert all the number in the map and calculate the frequency and if the frequency is greater than 2 then decrease it to 2.
then Insert back map.first map.second number of times to the given vector.
*/
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