class Solution {
public:
    int numDifferentIntegers(string word) {
     
        
        set<string> st;
        int n= word.size();
        
        for(int i=0; i<n; i++)
        {
            string tmp= "";
            while(i<n && word[i] >= 48 && word[i] <=57) {
                tmp.push_back(word[i++]);
            }
            
            if(tmp.size() > 0)
            {
                int j= 0;
                while(j<tmp.size() && tmp[j] == '0') {
                    j++;
                }
                st.insert(tmp.substr(j));
            }
        }
        
        return st.size();
    }
};