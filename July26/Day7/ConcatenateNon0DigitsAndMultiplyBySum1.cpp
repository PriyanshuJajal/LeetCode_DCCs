// LEETCODE 3754. Concatenate Non-Zero Digits and Multiply by Sum I

// Time complexity: O(logn)
// Space complexity: O(1)



class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0 , sum = 0;
        long long t = 1;

        while(n != 0) {
            int r = n % 10;
            n /= 10;
            if (r == 0) continue;

            x += r * t;
            t *= 10;
            sum += r;
        }
        return x * sum;
    }
};