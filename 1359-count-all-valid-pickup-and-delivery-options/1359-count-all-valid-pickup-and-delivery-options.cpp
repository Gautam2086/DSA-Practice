class Solution {
public:
    // Formula: n! {Pickups} * 1*3*5*(2n-1) {Deliveries arrangement}
    int countOrders(int n) {
        
        long mod= 1e9+7;
        long res= 1;
        
        for(int i=1; i<=n; i++)
        {
            res *= i;
            res = res % mod;
            
            res *= (2*i-1);
            res = res % mod;
        }
        return res%mod;
    }
};