// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //pair<int,int>
        
        int m= matrix.size();
        int n= matrix[0].size();
        int dir= 1;
        int i= 0, j= 0;
        
        while(i>=0 && j>=0 && i<m && j<n)
        {
            if(matrix[i][j] == 1) {
                matrix[i][j] = 0;
                if(dir == 0)
                    dir= 1;
                else if(dir == 1)
                    dir= 2;
                else if(dir == 2)
                    dir= 3;
                else if(dir == 3)
                    dir= 0;
            }
            
            if(dir == 0) {
                i--;
                if(i<0) return {i+1, j};
            }
                
            else if(dir == 1) {
                j++;
                if(j>=n) return {i, j-1};
            }
                
            else if(dir == 2) {
                i++;
                if(i>=m) return {i-1, j};
            }
                
            else if(dir == 3) {
                j--;
                if(j<0) return {i, j+1};
            }
                
        }
        
        return {};
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends