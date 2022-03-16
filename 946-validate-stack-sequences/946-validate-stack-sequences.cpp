class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j= 0;                               // to iterate popped vector
        
        for(int i: pushed)
        {
            st.push(i);
            
            while(!st.empty() && st.top() == popped[j]) {
                st.pop(); 
                j++;
            }   
        }
        
        if(j == popped.size())                  // means all elements have been popped
            return true;
        return false;
    }
};