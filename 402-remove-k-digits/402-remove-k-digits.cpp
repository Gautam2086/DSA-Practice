class Solution {
public:
/* 
-Our aim is to remove digit nums[i] starting from left where num[i]>nums[i+1]
-Using stack (here used stack) we compare the top element the present element
-If top element>present element we pop the top element from the stack (or string) and push the       present element
-If more element are still left to be removed i.e k>0 we remove the elements from the end of the     string(stack)
-We check if first element (character) is 0
-if YES then we reverse the string and remove the elements from the end till no zeros are left at     the back of the string. Then we reverse the string again.  
TC: O(n), SC: O(n)
*/
    
    string removeKdigits(string num, int k) {
        
        stack<char> st;
        
        int i= 0;
        for(; i<num.length() && k>0; i++)
        {
            while(k>0 && !st.empty() && num[i]-'0' < st.top()-'0') {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(!st.empty() && k>0)           // for edge cases like: num= "13579", k=3
        {
            st.pop();
            k--;
        }
        
        string ans= "";                     // Build ans string
        while(!st.empty()) {                
            ans= st.top() + ans;            // iterate in reverse fashion
            st.pop();
        }
        
        ans= ans + num.substr(i, num.length());   //append remaining elements(if any) of num in ans
        
        //trim leading zeros in case of 00200
        i= 0;
        while(i<ans.length()-1 && ans[i] == '0')
            i++;
        
        ans.erase(0, i);
        
    
        if(ans == "")
            return "0";
        else
            return ans;
    }
};