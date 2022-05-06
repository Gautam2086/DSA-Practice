class Solution {
public:
    string removeDuplicates(string s) {
        string ans= "";
        for(auto ch: s) 
        {
            if(ans.size() == 0)
                ans.push_back(ch);
            else if(ans.back() == ch)
                ans.pop_back();
            else
                ans.push_back(ch);
        }
        return ans;
    }
};