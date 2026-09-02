#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Check whether placing num at board[row][col] is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {

        for (int i = 0; i < 9; i++) {

            // Check row
            if (board[row][i] == num)
                return false;

            // Check column
            if (board[i][col] == num)
                return false;

            // Check 3x3 sub-box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;

            if (board[boxRow][boxCol] == num)
                return false;
        }

        return true;
    }

    // Backtracking function
    bool solve(vector<vector<char>>& board) {

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                // Find an empty cell
                if (board[row][col] == '.') {

                    // Try digits 1 to 9
                    for (char num = '1'; num <= '9'; num++) {

                        if (isValid(board, row, col, num)) {

                            // Place the number
                            board[row][col] = num;

                            // Recursively solve remaining board
                            if (solve(board))
                                return true;

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }

                    // No valid number found
                    return false;
                }
            }
        }

        // All cells are filled
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};