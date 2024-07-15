class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // Mark boundary 'O's and their connected 'O's
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][cols - 1] == 'O') {
                dfs(board, i, cols - 1);
            }
        }

        for (int i = 0; i < cols; ++i) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[rows - 1][i] == 'O') {
                dfs(board, rows - 1, i);
            }
        }

        // Flip 'O' to 'X', '2' back to 'O'
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '2') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int row, int col) {
        int rows = board.size();
        int cols = board[0].size();

        if (row < 0 || col < 0 || row >= rows || col >= cols || board[row][col] == 'X' || board[row][col] == '2') {
            return;
        }

        board[row][col] = '2';

        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1);
    }
};
