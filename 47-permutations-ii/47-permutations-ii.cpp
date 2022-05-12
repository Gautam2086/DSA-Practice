class Solution {
public:
    //https://www.youtube.com/watch?v=is_T6uzlTyg
    void permutations(vector<int> &nums, int i, vector<vector<int>> &ans)
    {
        if(i== nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_map<int,int> mp;
        
        for(int j=i; j<nums.size(); j++){
            if(mp.find(nums[j])!= mp.end())
                continue;
            mp.insert({nums[j],1});      //AsSoonAs we put no. at ith place we add it in map
            swap(nums[i],nums[j]);       //Keeping all numbers on each ith place from 1 to N
            permutations(nums,i+1,ans);
            swap(nums[i],nums[j]);       //Backtack as we have swapped in original
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
  
       vector<vector<int>> ans;
        int n= nums.size();
        if(n<= 1){
            return {nums};
        }
        permutations(nums,0,ans);
        return ans;        
    }
};