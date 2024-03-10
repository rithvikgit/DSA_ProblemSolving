class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int val ){
        for(int i=0;i<board.size();i++){
            //row check
            if(board[row][i]== val){
                return false;
            }
            //col check
            if(board[i][col]==val){
                return false;
            }
            //3*3 matrix check
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n = board[0].size();

        for(int row =0;row<n;row++){
            for(int col = 0; col<n ; col++ ){

                //cell empty
                if(board[row][col]=='.'){
                    for(int val = '1'; val<='9' ; val++ ){
                        if(isSafe(row,col,board,val)){
                            board[row][col]=val;
                            //recursive call
                            bool aheadSolutionPossible = solve(board);
                            if(aheadSolutionPossible)
                                return true;
                            else{
                                board[row][col]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        solve(board);


    }
};