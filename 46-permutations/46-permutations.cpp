class Solution {
public:
    void permutations(vector<int> nums, int i, vector<vector<int>> &ans)
    {
        if(i== nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int j=i; j<nums.size(); j++){
            swap(nums[i],nums[j]);
            permutations(nums,i+1,ans);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n= nums.size();
        
        if(n<= 1){
            return {nums};
        }
        
        permutations(nums,0,ans);
        return ans;
    }
};