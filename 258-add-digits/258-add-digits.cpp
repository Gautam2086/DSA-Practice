class Solution {
public:

    int helper(int num)
    {
        if(num < 10)                        // base case
            return num;
            
        if(num / 10 == 0)
            return num;
        
        long long sum= 0;
        while(num) {
            sum += num%10;
            num= num/10;
        }    
        
        return helper(sum);
    }
    
    int addDigits(int num) {
        return helper(num);
    }
};