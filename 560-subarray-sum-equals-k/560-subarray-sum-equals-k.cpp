/*
Can we replicate the calculation of sum in some other way? Basically in the
above for loops what we calculate is sum[i,j] meaning sum from index i to
index j. The same thing can be calculated by calculating sum[0, i] , sum[0,j]
and then sum[i,j] = sum[0,j] - sum[0,i], by doing so , we eliminate the need
of having a second pointer, this can be calculated in linear time. Now, if
sum[i,j] == 7, thats all you want. At this stage this problem has some
similarities with 2 sum problem. In two sum problem we used hashmap, we can
use hashmap here as well to record the sum as key and the difference between
sum and target as value. While iterating through the array, the moment we see a key which is difference between
sum and target, we can safely increase the count of result as we know there exists a sum[0,i] which we already recorded in the map.
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans= 0;
        int sum= 0;
        int n= nums.size();
        
        unordered_map<int, int> mp;         // < sum , freq >  
        mp.insert({0, 1});                  // for ex: [2,5,9] where k=2, we miss out case for i=0
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            
            if(mp.find(sum-k) != mp.end()) {
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        
        return ans;
    }
};