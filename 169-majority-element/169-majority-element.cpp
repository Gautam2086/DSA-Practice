class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(auto i: nums) {
            mp[i]++;
        }
        
        int mxFreq= 0;
        int mxEle= 0;
        for(auto i: mp) {
            if(i.second > mxFreq) {
                mxFreq= i.second;
                mxEle= i.first;
                
            }
                
        }
        
        return mxEle;
    }
};