// Rotate Image
// You are given an n x n 2D matrix representing a picture, rotate the image by 90 degrees (clockwise).

// You have to rotate the picture in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Example
// input      output
// 1 2 3       7 4 1
// 4 5 6 => 8 5 2
// 7 8 9       9 6 3

// Constraints:
// 1 <= n <= 20
// -value of matrix[i][j] may be negative.

class Solution {
public:
vector<vector<int>>  rotateimage(vector<vector<int>> & matrix){
  //Write your code here 
       int n = matrix.size();

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

      return matrix;

     }
};