class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n= height.size();
        int ans= INT_MIN;
        int lo=0, hi=n-1;
        
        while(lo<hi)
        {
            int area= min(height[lo], height[hi]) * (hi-lo);
            ans = max(ans, area);
            
            if(height[lo] > height[hi])     // shift hight pointer
                hi--;
            else                            // shift lo pointer
                lo++;
        }
        
        return ans;
    }
};