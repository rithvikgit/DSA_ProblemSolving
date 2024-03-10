// Board Filling
// You have given a rectangular board of M × N squares. You also have unlimited number of standard block pieces of 1 × 2 squares. You are allowed to rotate the pieces. You are asked to place as many blocks as possible on the board so as to meet the following conditions:

//1. Each block completely covers two squares.

//2. No two blocks overlap.

//3. Each block lies entirely inside the board. It is allowed to touch the edges of the board.

// Find the maximum number of blocks, which can be placed under these restrictions.

// Input In a single line you are given two integers M and N — board sizes in squares (1 ≤ M ≤ N ≤ 16).

// Output Output one number — the maximal number of blocks, which can be placed.

class Solution{
    public:
    int boardfill(int n,int m){

      return(n*m)/2;
    
    }
};


