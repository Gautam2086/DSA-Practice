class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        sort(tiles.begin(), tiles.end());
        int n= tiles.size();
        int ans= 0;
        int curr_total= 0;
        int right= 0;
        
        for(int i=0; i<n; i++)
        {
            int start= tiles[i][0];
            int end= start+carpetLen-1;
            
            while(right < n && tiles[right][1] < end) {
                curr_total += tiles[right][1]-tiles[right][0]+1;
                right++;
            }
            
            if(right == n || tiles[right][0] > end) {
                ans= max(ans, curr_total);
            }
            else {                                 // some part of next tile is left to be covered
                ans= max(ans, curr_total+end-tiles[right][0]+1);
            }
            
            curr_total -= tiles[i][1]-tiles[i][0]+1;    // move sliding window
        }
        
        return ans;
    }
};