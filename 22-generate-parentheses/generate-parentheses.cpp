class Solution {
public:
    void backtrack(string current, int open, int close, int n,
                   vector<string>& result) {

        // A complete valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have opening brackets left
        if (open < n) {
            backtrack(current + "(", open + 1, close, n, result);
        }

        // Add ')' only when it won't make the string invalid
        if (close < open) {
            backtrack(current + ")", open, close + 1, n, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;

        backtrack("", 0, 0, n, result);

        return result;
    }
};