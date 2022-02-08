class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        
        int rem = num % 9;
        if(rem == 0 && num > 0)
            rem = 9;
        
        return rem;
    }
};