class Solution {
public:
    int count = 0;

    void solve(int row, int n, vector<bool>& col,
               vector<bool>& diag1, vector<bool>& diag2) {
        
        // All queens are placed
        if (row == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {

            // Check if column or diagonal is already occupied
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;

            // Place queen
            col[c] = true;
            diag1[row + c] = true;
            diag2[row - c + n - 1] = true;

            solve(row + 1, n, col, diag1, diag2);

            // Backtrack
            col[c] = false;
            diag1[row + c] = false;
            diag2[row - c + n - 1] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, col, diag1, diag2);

        return count;
    }
};