class Solution {
public:
    // TC: O(n*logn) + O(n)    
    // => n: traversing in array, log n: inserting in set, n for placing set ele in array front
    // SC: O(n)
    
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        
        for(int x: nums) 
            s.insert(x);
        

        int n= s.size();
        
        int i= 0;
        for(auto x: s)
            nums[i++]= x;
            
        return n;
    }
};