class Solution {
public:
    vector<vector<string>> result;
    
    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& cols,
                   vector<bool>& diag1,
                   vector<bool>& diag2) {
        
        // All queens are placed
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            
            // Check column and diagonals
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
                continue;

            // Place queen
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n - 1] = true;

            // Move to next row
            backtrack(row + 1, n, board, cols, diag1, diag2);

            // Remove queen (backtracking)
            board[row][col] = '.';
            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(0, n, board, cols, diag1, diag2);

        return result;
    }
};