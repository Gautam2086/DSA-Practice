class Solution {
public:
// The first algorithm is straight-forward. Let's think about the simplest case: how to remove 1 digit from the number so that the new number is the smallest possible？ Well, one can simply scan from left to right, and remove the first "peak" digit; the peak digit is larger than its right neighbor. One can repeat this procedure k times, and obtain the first algorithm
    
    string removeKdigits(string num, int k) {
        
        while(k>0)
        {
            int n= num.size();
            int i= 0;
            
            while(i<n-1 && num[i] <= num[i+1])
                i++;
            num.erase(i, 1);
            k--;
        }
        
        // trim leading zeros
        int i= 0;
        while(i< num.length()-1 && num[i]=='0')
            i++;
        
        num.erase(0, i);
        
        if(num == "")
            return "0";
        else
            return num;
    }
};