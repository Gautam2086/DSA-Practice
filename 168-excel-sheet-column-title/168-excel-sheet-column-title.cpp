class Solution {
public:
    string convertToTitle(int N) {
        string res= "";
        
        while(N>0)
        {
            int rem= N % 26;
            
            if(rem == 0) {
                res= 'Z'+ res;
                N= N/26 - 1;
            }
            else
            {
                char ch= 'A' + rem - 1;
                res= ch + res;
                N= N/26;
            }
        }
        return res;
    }
};