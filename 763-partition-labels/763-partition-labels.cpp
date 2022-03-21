class Solution {
public:
    // TC: O(n)
    // SC: O(n) 
    vector<int> partitionLabels(string s) {
        
        unordered_map<char, int> mp;               // to store last indices of each char
        
        int i= 0;
        for(auto ch: s) {                          // {char, last idx}
            mp[ch]= i;
            i++;
        }
        
        vector<int> res;                           // store length of partitins
        
        int prev= -1;
        int maxi= 0;
        
        for(int i=0; i<s.size(); i++)
        {
            maxi= max(maxi, mp[s[i]]);             // max range of curr char
            
            if(i == maxi) {                        // if we reach maxi then calc len of part
                res.push_back(maxi-prev);          // store len of part in res vector
                prev= i;                           // update prev
            }
        }
        
        return res;
    }
};