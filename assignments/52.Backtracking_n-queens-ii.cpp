class Solution {
public:
    int totalNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> arr(n, string(n, '.'));

        queenTry(ans, arr, 0, n);
        return ans.size();    
        
    }

    
    void queenTry(vector<vector<string>>& ans, vector<string>& arr, int row, int n) {
        if (row == arr.size()) {
            ans.push_back(arr);
            return;
        }
        for (int col = 0; col < arr.size(); col++) {
            if (safe(arr, col, n, row)) {
                arr[row][col] = 'Q';
                queenTry(ans, arr, row + 1, n);
                arr[row][col] = '.';
            }
        }
    }

    bool safe(const vector<string>& arr, int c, int n, int r) {
        for (int k = 0; k < n; k++) {
            if (arr[r][k] == 'Q' || arr[k][c] == 'Q') {
                return false;
            }
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (arr[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
            if (arr[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    
    
};