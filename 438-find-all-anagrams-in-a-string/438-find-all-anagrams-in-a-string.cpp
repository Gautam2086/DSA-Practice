class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> res;
        unordered_map<char, int> pCount;
        unordered_map<char, int> sCount;
        int k= p.length();
        
        for(auto x: p) {
            pCount[x]++;
        }
        
        int i=0, j= 0;
        
        while(j<s.length())
        {
            sCount[s[j]]++;
    
            if(j-i+1 < k)
                j++;
            
            else if(j-i+1 == k)
            {
                if(pCount == sCount)
                   res.push_back(i);
                
                if(sCount[s[i]] == 1)
                    sCount.erase(s[i]);
                else
                    sCount[s[i]]--;
                
                i++; j++;
            }
        }
        return res;
    }
};