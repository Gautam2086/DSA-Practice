class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int prof= 0;
        int n= prices.size();
        int mnPrice= INT_MAX;
        
        for(int i=0; i<n; i++) {
            mnPrice= min(mnPrice, prices[i]);
            prof= max(prof, prices[i]-mnPrice);
        }
        
        return prof;
    }
};