class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;              // stores nums[j]
        
        int thirdEle= INT_MIN;      // nums[k]
        
        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i] < thirdEle)
                return true;
                              // nums[k]    nums[j]
            while(!st.empty() && st.top() < nums[i]) {
                thirdEle = st.top();
                st.pop();
            }
            st.push(nums[i]);        // stores nums[j] ie the max ele
        }
        return false;
    }
};