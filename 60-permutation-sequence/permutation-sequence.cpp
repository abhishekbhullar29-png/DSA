class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;

        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }

        string result = "";

        k--;  // Convert to 0-based index

        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
        }

        for (int i = n; i >= 1; i--) {

            int index = k / fact;

            result += to_string(numbers[index]);

            numbers.erase(numbers.begin() + index);

            k = k % fact;

            if (i > 1) {
                fact /= (i - 1);
            }
        }

        return result;
    }
};