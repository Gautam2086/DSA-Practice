/*
Here the idea is to just consider the zero as -1 and take the prefix sum and maintain a hashmap where the key is the prefixSum and value is its index. Whenever we see the prefixSum inside the hashmap, then we can update our maxLength = max(maxLength, i - map.get(prefixSum)). otherwise we just put the prefixSum and index to the hashmap.

+1 -> when encounter 1
-1 -> when encounter 0
calculate Prefix sum
TC: O(n)
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    
        int ans= 0; 
        int sum= 0;
        unordered_map<int, int> mp;         // (sum, idx at which sum occured in leftmost place)
        mp[0]= -1;                          // for cases [0,1] 
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i]==1 ? 1 : -1;
            
            auto it= mp.find(sum);
            
            if(it != mp.end()) {
                 ans= max(ans, i-mp[sum]);
            }
            else {
                mp[sum]= i;
            }
        }
        
        return ans;  
    }
};