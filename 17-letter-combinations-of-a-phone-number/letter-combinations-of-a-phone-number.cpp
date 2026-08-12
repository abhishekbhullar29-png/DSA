class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;

        function<void(int, string)> backtrack =
            [&](int index, string current) {

                if (index == digits.length()) {
                    result.push_back(current);
                    return;
                }

                string letters = mapping[digits[index] - '0'];

                for (char ch : letters) {
                    current.push_back(ch);
                    backtrack(index + 1, current);
                    current.pop_back();
                }
            };

        backtrack(0, "");

        return result;
    }
};