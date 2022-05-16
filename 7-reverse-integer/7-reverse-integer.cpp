class Solution {
public:
    int reverse(int x)
    {
        long long n = x;
        long long digit;
        long long rev= 0;
         
        if(n<0) {
            //x= -1*x;                  // gives runtime error
            x= abs(x);
        }
        while(x>0)
        {
            digit= x%10;
            rev= (rev*10) + digit;
            x= x/10;
        }
        if(rev>= INT_MAX || rev<=INT_MIN) {         
            return 0;
        }
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
        
        if(n<0) {
            rev= -1*rev;
        }
        
        return rev;
    }
};