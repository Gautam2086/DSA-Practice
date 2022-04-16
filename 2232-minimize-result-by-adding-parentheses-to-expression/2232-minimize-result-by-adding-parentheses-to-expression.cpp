class Solution {
public:
    // a * (b + c) * d
    
    // st means we are adding opening bracket just after the index st
	// end means we are adding closing bracket just after the index end
	// br is the index of '+'
    
    int findVal(string s, int st, int end, int br)
    {
		// valf is the value before the opening bracket
		// valm is the value between the brackets consisting the '+'
		// vale is the value after the closing bracket
        int valf = 0, valm = 0, vale = 0;
        if(st == 0)
            valf = 1;
        else
            valf = stoi(s.substr(0, st));
        
        if(end == s.size())
            vale = 1;
        else
            vale = stoi(s.substr(end));
        
        valm = stoi(s.substr(st, br - st)) + stoi(s.substr(br + 1, end - br - 1));
        return valf * valm * vale;
    }
    
    string minimizeResult(string s)
    {
        int id = s.find('+');
        int n = s.size();
        
        int mn = INT_MAX;
		
		// to keep track of the place of brackets such that the result at that place is minimum
        int st = -1, end = -1;
        
        for(int i = 0; i < id; i++)
        {
            for(int j = id + 2; j <= n; j++)
            {
                int v = findVal(s, i, j, id);
                if(v < mn)
                    mn = v, st = i, end = j;
            }
        }
        string res;
        for(int i = 0; i < n; i++)
        {
            if(i == st)
                res += '(';
            else if(i == end)
                res += ')';
            res += s[i];
        }
        
        if(end == n)
            res += ')';
        
        return res;
    }
};
    