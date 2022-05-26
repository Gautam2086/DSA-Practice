class Solution {
public:
    int hammingWeight(uint32_t n){
        int count= 0;
        int ans;
        
        while(n!= 0){
            ans= n& 1;
            if(ans== 1){
                count++;
            }
            n= n>> 1;
        }
        return count;
    }
};