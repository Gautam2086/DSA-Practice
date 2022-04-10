class Solution {
public:
    
    void clear(vector<int> &v) {
        v.pop_back();
        return;
    }
    
    void doub(vector<int> &v) {
        
        int a= v[v.size()-1];

        int doubl= a*2;
        v.push_back(doubl);
        return;
    }
    
    void plus(vector<int> &v) {
        
        int a= v[v.size()-1];
        int b= v[v.size()-2];

        int sum= a+b;
        v.push_back(sum);
        return;
    }
    
    int calPoints(vector<string>& ops) {
        
        vector<int> v;
        for(auto s: ops){
            
            if(s == "C")
                clear(v);
            else if(s == "D")
                doub(v);
            else if(s == "+")
                plus(v);
            else {
                v.push_back(stoi(s));
            }
        }
        
        int sum= accumulate(v.begin(), v.end(), 0);
        
        return sum;
    }
};