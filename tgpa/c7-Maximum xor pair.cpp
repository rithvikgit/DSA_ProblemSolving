// Maximum xor pair
// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
// Or
// You are tasked with finding the maximum XOR (exclusive OR) value that can be achieved by XORing any two elements in a given integer array nums. The XOR operation is defined as a bitwise operation where 0 XOR 0 = 0, 1 XOR 0 = 1, 0 XOR 1 = 1, and 1 XOR 1 = 0.

// Input Format:

// The first line of input contains an integer n, representing the number of elements in the array.
// The second line contains nspace-separated integers, the elements of the arraynums.
// Output Format:

// Output a single integer, the maximum XOR value that can be obtained by XORing any two elements in the array.
// Sample Input 1:

// 6
// 3 10 5 25 2 8
// Sample Output 1:

// 28
// Explanation:

// The maximum result is obtained by XORing 5 and 25, which equals 28 (5 XOR 25 = 28).
// Sample Input 2:

// 12
// 14 70 53 83 49 91 36 80 92 51 66 70
// Sample Output 2:

// 127
// Explanation:

// The maximum result is obtained by XORing any appropriate pair of numbers from the given array that yields the result of 127.
// Constraints:
// 1 <= nums.length <= 10000
// 0 <= nums[i] <= 100000000

//leetcode 421

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
      // write your code here 
      int maxXor = 0;

      for(int i = 0 ; i<nums.size() ; i++){
        for(int j = i+1; j<nums.size() ;j++){
          maxXor= max(maxXor, nums[i]^nums[j]);
        }
      }

      return maxXor;

    }
};