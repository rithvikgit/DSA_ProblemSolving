// New Matrix
// Tuntun is very creative. She is thinking of a new way to modify the matrix but she is very weak in coding so help her to do so. You are given a m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Input Format

// - The first line contains two space-separated integers ‘N’ and ‘M’, denoting the no. of the rows and columns of the matrix.

// - The next 'N' lines will contain ‘M’ space separated integers representing the elements of the matrix.

// Output Format:
// print the modified grid in a separate line.
// Example
// 1 1 1                  1 0 1
// 1 0 1     =>           0 0 0
// 1 1 1                  1 0 1
// Constraints:
// - m == matrix.length
// - n == matrix[0].length
// - 1 <= m, n <= 200
// - (-231) <= matrix[i][j] <= (231 - 1)

class Solution {
    public void solve(int n, int m, int[][] matrix) {
      //Write your code here
      boolean row = false, col = false;

        for (int i = 0; i < matrix.length; i++)
        for (int j = 0; j < matrix[0].length; j++)
            if (matrix[i][j] == 0) {
            if (i == 0) row = true;
            if (j == 0) col = true;
            matrix[0][j] = 0;
            matrix[i][0] = 0;
            }

        for (int i = 1; i < matrix.length; i++)
        for (int j = 1; j < matrix[0].length; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            matrix[i][j] = 0;

        if (row)
        for (int j = 0; j < matrix[0].length; j++)
            matrix[0][j] = 0;

        if (col)
        for (int i = 0; i < matrix.length; i++)
            matrix[i][0] = 0;

        for(int i=0;i<matrix.length;i++){
        for(int j=0;j<matrix[0].length;j++){
          System.out.print(matrix[i][j]+" ");
        }
        System.out.println();
      }
      

       
  }
}