class Solution {
public:
/*
Imagine these matrix values as a linear array : 1,3,5,7,10,11,16,20,23,30,34,60
All values are in increasing order in this linear array
so use binary search to find the required element

TC: O(log(n*m))
*/
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m= matrix.size();           // row
        int n= matrix[0].size();        // col
        
        int lo= 0;
        int hi= (m*n)-1;                // last index in matrix
        
        while(lo<=hi)
        {
            int mid= lo+ (hi-lo)/2;
            
            if(matrix[mid/n][mid%n] == target)
                return true;
            
            else if(matrix[mid/n][mid%n] < target) {
                lo= mid+1;
            }
            else
                hi= mid-1;
        }
        return false;
    }
};