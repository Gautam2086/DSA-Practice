class Solution {
public:
/*
Algo:

- Sort the Vector.
- We can make the lightest & heaviest person to go together.
  using Two pointer appraoch i is the lightest person & j is the heaviest.
- Traversing till start <= end.
- if sum of lightest & heaviest person are under limit then both can go together, updating     i & j both.
- If sum exceeds the limit, then heaviest person will go alone, hence updating only the j     pointer.
- increment the count
- Return cnt

TC:- O(NlogN)
SC:- O(1)
*/
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n= people.size();
        sort(people.begin(), people.end());
        int ans= 0;
        
        int lo= 0;
        int hi= n-1;
        
        while(lo<=hi)
        {      
            int sum= people[lo]+people[hi];
            
            // lightest person + heaviest person sum <= limit
            // they can go together
            if(sum <= limit) {
                ans++;                  // increment boats
                lo++;   hi--;
            }
            
            // if sum is over the limit,
            // heaviest will go alone.
            else {
                ans++;                  // increment boats
                hi--;
            }
        }
        
        return ans;
    }
};