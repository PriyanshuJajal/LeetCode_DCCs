// LEETCODE 2147. Number of Ways to Divide a Long Corridor

// Along a long library corridor, there is a line of seats and decorative plants. You are given a 0-indexed string corridor of length n consisting of letters 'S' and 'P' where each 'S' represents a seat and each 'P' represents a plant.

// One room divider has already been installed to the left of index 0, and another to the right of index n - 1. Additional room dividers can be installed. For each position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can be installed.

// Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number of plants. There may be multiple ways to perform the division. Two ways are different if there is a position with a room divider installed in the first way but not in the second way.

// Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 109 + 7. If there is no way, return 0.

 

// Example 1:


// Input: corridor = "SSPPSPS"
// Output: 3
// Explanation: There are 3 different ways to divide the corridor.
// The black bars in the above image indicate the two room dividers already installed.
// Note that in each of the ways, each section has exactly two seats.
// Example 2:


// Input: corridor = "PPSPSP"
// Output: 1
// Explanation: There is only 1 way to divide the corridor, by not installing any additional dividers.
// Installing any would create some section that does not have exactly two seats.
// Example 3:


// Input: corridor = "S"
// Output: 0
// Explanation: There is no way to divide the corridor because there will always be a section that does not have exactly two seats.
 

// Constraints:

// n == corridor.length
// 1 <= n <= 105
// corridor[i] is either 'S' or 'P'.







// 🚀 Approach
// Traverse the corridor string and record the indices of all seats ('S').
// If the total number of seats is odd or zero, return 0 because it’s impossible to divide into valid sections.
// Count partitions:
//     Start from the second seat and consider pairs of seats (seatIdx[i] & seatIdx[i + 1]).
//     For each pair, calculate the number of plants (or length) between the end of the previous pair and the start of the next pair.
//     Multiply these counts together to get the total number of ways.
//     Use modulo 10⁹ + 7 to avoid overflow.
// The final product gives the number of valid ways to divide the corridor.

// 🕛 Complexity
// Time complexity: O(n)

// Space complexity: O(k)
// k = number of seats










class Solution {
    private static final int MOD = 1_000_000_007;

    public int numberOfWays(String corridor) {
        int n = corridor.length();
        java.util.List<Integer> seatIdx = new java.util.ArrayList<>();

        // Collect indices of seats
        for (int i = 0; i < n; i++) {
            if (corridor.charAt(i) == 'S') {
                seatIdx.add(i);
            }
        }

        // If odd number of seats or no seats, return 0
        if (seatIdx.size() % 2 == 1 || seatIdx.size() == 0) {
            return 0;
        }

        long cnt = 1;
        int prevEndIdx = seatIdx.get(1);

        // Iterate over seat pairs
        for (int i = 2; i < seatIdx.size(); i += 2) {
            int len = seatIdx.get(i) - prevEndIdx;
            cnt = (cnt * len) % MOD;

            prevEndIdx = seatIdx.get(i + 1);
        }

        return (int) cnt;
    }
}