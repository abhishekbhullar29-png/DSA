
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int index) {
        // All characters matched
        if (index == word.size()) {
            return true;
        }

        // Check boundaries and character match
        if (i < 0 || j < 0 ||
            i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[index]) {
            return false;
        }

        // Mark cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Search in four directions
        bool found =
            dfs(board, word, i + 1, j, index + 1) ||
            dfs(board, word, i - 1, j, index + 1) ||
            dfs(board, word, i, j + 1, index + 1) ||
            dfs(board, word, i, j - 1, index + 1);

        // Restore the cell
        board[i][j] = temp;

        return found;
    }
};
