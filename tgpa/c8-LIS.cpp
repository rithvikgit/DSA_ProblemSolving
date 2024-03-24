// LIS
// Longest Increasing Subsequence (LIS)
// Given an array arr[] of size N, find the length of the Longest Increasing Subsequence (LIS) in the array. The LIS is defined as the longest subsequence where each element is strictly greater than the preceding one.

// Input Format:

// The first line contains an integer N, the size of the array.
// The second line contains Nspace-separated integers representing the elements of the arrayarr[].
// Output Format:

// Output a single integer, the length of the longest increasing subsequence in the given array.
// Constraints:

// 1 <= N <= 2500
// -10^5 <= arr[i] <= 10^5, where arr[i] denotes the i-th element of the array arr[].
// Sample Inputs and Outputs:

// Input:

// 5
// 3 10 2 1 20
// Output:

// 3
// Explanation: The longest increasing subsequence is {3, 10, 20}, which has a length of 3.

// Input:

// 2
// 3 2
// Output:

// 1
// Explanation: The longest increasing subsequences are {3}and{2}, both with a length of 1.

// Input:

// 6
// 50 3 10 7 40 80
// Output:

// 4
// Explanation: The longest increasing subsequence is {3, 7, 40, 80}, which has a length of 4.

class Solution {
public:

    int f(int ind, int prev, int arr[],int n,vector<vector<int>> &dp){
        if(ind == n)return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int len = 0 + f(ind+1,prev,arr,n,dp);
        if(prev==-1||arr[ind]>arr[prev]){
          len = max(len,1+f(ind+1,ind,arr,n,dp));
        }
        return dp[ind][prev+1]=len;
    }     

    int lis(int arr[], int n) {
      //Write your code here 

      vector<vector<int>> dp(n,vector<int>(n+1,-1));
      return f(0,-1,arr,n,dp);
      
      

     }
};