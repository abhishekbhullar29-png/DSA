class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign of the answer
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long and make both positive
        long long a = dividend;
        long long b = divisor;

        a = abs(a);
        b = abs(b);

        long long quotient = 0;

        // Find quotient using powers of 2
        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Double divisor using left shift
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        // Apply sign
        if (negative)
            quotient = -quotient;

        // Keep result within 32-bit signed integer range
        if (quotient > INT_MAX)
            return INT_MAX;

        if (quotient < INT_MIN)
            return INT_MIN;

        return (int)quotient;
    }
};