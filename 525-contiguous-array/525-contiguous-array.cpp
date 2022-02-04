/*
+1 -> 1
-1 -> 0
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