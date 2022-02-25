class Solution {
public:
    // 2-Pointer approach
    // Time Complexity: O(len1+len2)
    // Space Complexity: O(1)
    
    int compareVersion(string version1, string version2) {
        int i=0, j=0;
        int len1= version1.size(); 
        int len2= version2.size();
        int n1= 0, n2= 0;          // Generate revisions (ie number) from digits before each dot(.)
        
        while(i<len1 || j<len2)
        {
            n1= 0;
            n2= 0; 
            
            while(i<len1 && version1[i] != '.') {       // Generate num n1
                n1= n1*10 + (version1[i]-'0');
                i++;
            }
            
            while(j<len2 && version2[j] != '.') {       // Generate num n2
                n2= n2*10 + (version2[j]-'0');
                j++;
            }
            
            if(n1 < n2)
                return -1;
            else if(n1 > n2)
                return 1;
            
            i++;    j++;                              // if (n1 == n2), check for rest of the string
        }
        
        return 0;
    }
};