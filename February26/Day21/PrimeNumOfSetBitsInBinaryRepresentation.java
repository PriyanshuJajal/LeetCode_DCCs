// LEETCODE 762. Prime Number of Set Bits in Binary Representation

// Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.

// Recall that the number of set bits an integer has is the number of 1's present when written in binary.

// For example, 21 written in binary is 10101, which has 3 set bits.
 

// Example 1:

// Input: left = 6, right = 10
// Output: 4
// Explanation:
// 6  -> 110 (2 set bits, 2 is prime)
// 7  -> 111 (3 set bits, 3 is prime)
// 8  -> 1000 (1 set bit, 1 is not prime)
// 9  -> 1001 (2 set bits, 2 is prime)
// 10 -> 1010 (2 set bits, 2 is prime)
// 4 numbers have a prime number of set bits.
// Example 2:

// Input: left = 10, right = 15
// Output: 5
// Explanation:
// 10 -> 1010 (2 set bits, 2 is prime)
// 11 -> 1011 (3 set bits, 3 is prime)
// 12 -> 1100 (2 set bits, 2 is prime)
// 13 -> 1101 (3 set bits, 3 is prime)
// 14 -> 1110 (3 set bits, 3 is prime)
// 15 -> 1111 (4 set bits, 4 is not prime)
// 5 numbers have a prime number of set bits.
 

// Constraints:

// 1 <= left <= right <= 106
// 0 <= right - left <= 104




// 🚀 Approach
// Prime Check Function
//     Implemented using the 6k ± 1 optimization for efficiency.
//     This avoids unnecessary divisions and reduces complexity to O(√n).
// Iterate Through Range
//     For each number between left and right, compute its set bit count using __builtin_popcount(i).
//     If the popcount is prime, increment the counter.
// Return the total count at the end.

// 🕛 Complexity
// Time complexity: O((right - left + 1) * √32) ~ O(n)
// Space complexity: O(1)









class Solution {
    public boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    public int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            if (isPrime(Integer.bitCount(i))) {
                cnt++;
            }
        }
        return cnt;
    }
}