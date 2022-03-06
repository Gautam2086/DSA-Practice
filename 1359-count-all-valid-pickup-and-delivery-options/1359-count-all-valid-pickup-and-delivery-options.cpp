class Solution {
public:
/* Formula: n! {Pickups} * 1*3*5*(2n-1) {Deliveries arrangement} 

https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/1823403/C%2B%2B-oror-Easy-To-Understand-oror-Full-Explanation-oror-Coimbanotrics
    
https://www.youtube.com/watch?v=GVWIUk5eID8
*/
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