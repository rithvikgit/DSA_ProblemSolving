// Median in a data stream
// Given that n integers are read from a data stream. Your task is to find the median of the elements read so far. Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the floor of the average of the two middle values.

// Example 1
// Input
// arr = [5,3,8]
// Output
// [5,4,5]
// Explanation
// After reading first element of stream, Median of [5] is 5 After reading second element of stream, Median of [5, 3] = floor((5+3)/2)=4 After reading third element of stream, Median of [5,3,8] = 5 ,it is the middle value of the sorted array So the output will be 5 4 5.

// Example 2:

// Input:

// arr = [1,2,3] 
// Output:

// [1,1,2]
// Constraints:
// 1 <= n <= 10000
// 0 <= arr[i] <= 100000


class Solution {
public:

    vector<int> findMedian(vector<int> &arr, int n) {
      // write your code here 

      priority_queue<int>maxHeap1;
      priority_queue<int>maxHeap2;
      vector<int>a;

      for(int i=0; i<n;i++){

        maxHeap2.push(arr[i]);
        int temp = maxHeap2.top();
        maxHeap2.pop();

        maxHeap1.push(-1*temp);
        if(maxHeap1.size()!=maxHeap2.size()){
          temp = maxHeap1.top();
          maxHeap1.pop();
          maxHeap2.push(-1*temp);
        }

        if(maxHeap1.size()!=maxHeap2.size()){
          a.push_back(maxHeap2.top());
        }
        else{
          int b;
          b=((double)(maxHeap2.top()*1.0 - maxHeap1.top()*1.0)/2);
          a.push_back(b);
        }

        
      }
      return a;

    }
};