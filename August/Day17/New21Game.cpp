// LEETCODE 837. New 21 Game

// Alice plays the following game, loosely based on the card game "21".

// Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.

// Alice stops drawing numbers when she gets k or more points.

// Return the probability that Alice has n or fewer points.

// Answers within 10-5 of the actual answer are considered accepted.

 

// Example 1:

// Input: n = 10, k = 1, maxPts = 10
// Output: 1.00000
// Explanation: Alice gets a single card, then stops.
// Example 2:

// Input: n = 6, k = 1, maxPts = 10
// Output: 0.60000
// Explanation: Alice gets a single card, then stops.
// In 6 out of 10 possibilities, she is at or below 6 points.
// Example 3:

// Input: n = 21, k = 17, maxPts = 10
// Output: 0.73278
 

// Constraints:

// 0 <= k <= n <= 104
// 1 <= maxPts <= 104

// 🚀 Approach
// Base Cases:
    // If k == 0, Alice doesn't draw any numbers, so her score is 0, which is ≤ n. Return 1.0.
    // If n >= k + maxPts - 1, Alice can reach any score ≤ n with certainty. Return 1.0.
// DP Array:
    // Let dp[i] be the probability of reaching score i.
    // Initialize dp[0] = 1.0 since Alice starts at 0.
// Sliding Window:
    // Maintain a running sum currProbSum of the last maxPts probabilities.
    // For each i from 1 to n, compute dp[i] = currProbSum / maxPts.
    // If i < k, Alice can still draw, so add dp[i] to currProbSum.
    // If i ≥ k, she stops drawing, so add dp[i] to the result res.
    // Subtract dp[i - maxPts] from currProbSum if it falls out of the window.
// Return:
    // Return the accumulated result res, which is the sum of probabilities for scores from k to n.

    

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;
        if (n >= k + maxPts - 1) return 1.0;

        vector<double> dp(n + 1 , 0.0);
        dp[0] = 1.0;
        double currProbSum = 1.0;
        double res = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = currProbSum / maxPts;
            if (i < k) currProbSum += dp[i];
            else res += dp[i];
            if (i - maxPts >= 0) currProbSum -= dp[i - maxPts];
        }
        return res;
    }
};