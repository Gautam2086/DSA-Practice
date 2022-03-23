class Solution {
public:
/*
- Think of reverse
- Convert target to startValue
- by dividing target by 2 (if divisible) or by adding 1 in target 
- and move frwrd similarly with resultant value of prev step till you reach startValue
- if at any point target <= startValue then we can just add 1 (and not divide by 2)

- Time Complexity: O(logN)
- Space Complexity: O(1)
*/
    int brokenCalc(int startValue, int target)
    {
        if(startValue >= target)                // Edge case
            return startValue-target;
        
        int steps= 0;
        
        // if target <= startValue, then we can just add 1 (and not divide by 2)
        while(target > startValue)  
        {
            if(target + 1 == startValue)
                return steps+1;
            if(target / 2 == startValue)
                return steps+1;
            
            if(target % 2 == 0) {
                target /= 2;
            }
            else {
                target += 1;
            }
            
            steps++;
        }
        
        return steps+startValue-target;
    }
};