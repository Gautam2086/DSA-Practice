/*
EXPLANATION 1:
We have two types of operations: double odd numbers, and halve even numbers. We can try to sort all numbers, and increase the smallest number (if it's odd) and decrease the largest number (if it's even). This can get quite complicated.

Intuition 1: we can divide even numbers multiple times - till we get an odd number, but we can only double odd numbers once. After that, it will become an even number.

Intuition 2: Even numbers never increase.

Flip: we can double all odd numbers first, so we can get forget of the second operation. Now, we only need to decrease the largest number - while it's even, which results a very simple solution.

Solution
Double odd numbers and put all numbers into a max heap. Track the smallest number. Track the minimum difference between the top of the heap and the smallest number. While the top of the heap is even, remove it, divide, and put back to the heap.

EXPLANATION 2:
1. To decrease the deviation either increase the minn or decrease the maxx.
2. Now, Make every number as maximum as possible to eliminate one operation(increase the minn)
3. since every element is as maximum as possible , you can not increase any number further
4. Now we are left with just one operation decrease the maxx
5. So perform this operation as many times as u can and keep track of the min_deviation
*/
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int> pq;                 // Max heap
        
        int mn= INT_MAX;
        int diff= INT_MAX;
        
        for(auto i: nums) {                     // multiply all odd nos. by 2
            if(i % 2)
                i*=2;
            mn= min(mn, i);
            pq.push(i);
        }
        
        while(pq.top() % 2 == 0)                // until no. at top of pq is even
        {
            int mx= pq.top();   pq.pop();       // update max ele
            
            diff= min(diff, mx-mn);             // update diff ( ie minimize the diff)
            
            pq.push(mx/2);                      // divide no. by 2, as it is even
            mn= min(mn, mx/2);                  // update min ele
        }
        
        return min(diff, pq.top()-mn);
    }
};