
class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string s1, string s2) {
        if (s1 == s2)
            return true;

        if (s1.size() != s2.size())
            return false;

        string key = s1 + "#" + s2;

        if (memo.find(key) != memo.end())
            return memo[key];

        // Check if both strings have the same characters
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b)
            return memo[key] = false;

        int n = s1.size();

        // Try every possible split
        for (int i = 1; i < n; i++) {
            // Case 1: No swapping
            if (solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: Swapping
            if (solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        memo.clear();
        return solve(s1, s2);
    }
};
