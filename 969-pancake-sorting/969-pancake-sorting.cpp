class Solution {
public:
    void flip(vector<int>& arr1, int k)      // this func reverses the order of first k elements
    {
        
      int start= 0;
      int temp= 0;

      while(start < k)
      {
        temp= arr1[start];
        arr1[start]= arr1[k];
        arr1[k]= temp;
        start++;
        k--;
      }
    }
    
    int maxElement(vector<int>& arr1, int n) // gives index of max ele in array 0th idx to nth idx
    {
      int max_idx= 0;

      for(int i=0; i<n; i++)
      {
        if(arr1[i] > arr1[max_idx])
          max_idx= i;
      }

      return max_idx;
    }
    
    vector<int> pancakeSort(vector<int>& arr) 
    {
        
      vector<int> v;
      vector<int> arr1= arr;
      int n= arr1.size();

      for(int curr_size= n; curr_size>1; curr_size--)
      {

        int mxIdx= maxElement(arr1, curr_size);

        if(mxIdx != curr_size-1)    // check if max ele is not at the last idx
        {
          // To move max ele at the first
          v.push_back(mxIdx+1);
          flip(arr1, mxIdx);       // 5, 1, 4, 3, 2,
                                   // 2, 3, 4, 1, 5
                                   // 4, 3, 2, 1, 5
          v.push_back(curr_size);
          flip(arr1, curr_size-1);
        }

      }
        
      return v;
    }
};