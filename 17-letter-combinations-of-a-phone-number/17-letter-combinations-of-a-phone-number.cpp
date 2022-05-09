class Solution {
public:
    vector<string> res;
    vector<string> v= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};   
    // mapping of digits to letters
    
    void helper(string& digits, string op) {
        
        if(digits.size() == 0) {
            res.push_back(op);
            return;
        }
        
        string tmp = v[digits[0]-'0'];
        string digits_left = digits.substr(1);
        
        for(int i=0; i<tmp.length(); i++) {
            char prefix= tmp[i];
            helper(digits_left, op + prefix);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits == "" || digits.length() == 0)            // Base case
            return {};
        
        string op= "";
        helper(digits, op);
        
        return res;
    }
};