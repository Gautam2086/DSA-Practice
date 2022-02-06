class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        
        for(int x: nums) 
            s.insert(x);
        
        // for(int x: s) 
        //     cout<<x<<" ";
        int n= s.size();
        
        int i= 0;
        for(auto x: s)
            nums[i++]= x;
            
        return n;
    }
};