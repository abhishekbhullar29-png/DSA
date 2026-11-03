
class Solution {
public:
    vector<string> ans;

    void backtrack(string &s, int index, int parts, string current) {
        // If all 4 parts are created
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back(); // Remove last dot
                ans.push_back(current);
            }
            return;
        }

        // Try segment lengths 1, 2, and 3
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero is not allowed
            if (part.size() > 1 && part[0] == '0')
                continue;

            // Value must be between 0 and 255
            int num = stoi(part);

            if (num > 255)
                continue;

            backtrack(s, index + len, parts + 1,
                      current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        if (s.size() < 4 || s.size() > 12)
            return ans;

        backtrack(s, 0, 0, "");

        return ans;
    }
};
