// LEETCODE 3536. Maximum Product of Two Digits

// Time complexity: O(logn)
// Space complexity: O(1)

class Solution {
public:
    int maxProduct(int n) {
        int first = 0;
        int second = 0;

        while(n > 0) {
            int d = n % 10;
            if (d > first) {
                second = first;
                first = d;
            }
            else if (d > second) {
                second = d;
            }

            n /= 10;
        }

        return first * second;
    }
};