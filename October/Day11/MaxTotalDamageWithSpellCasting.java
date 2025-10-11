// LEETCODE 3186. Maximum Total Damage With Spell Casting

// A magician has various spells.

// You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.

// It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.

// Each spell can be cast only once.

// Return the maximum possible total damage that a magician can cast.

 

// Example 1:

// Input: power = [1,1,3,4]

// Output: 6

// Explanation:

// The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.

// Example 2:

// Input: power = [7,1,6,6]

// Output: 13

// Explanation:

// The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with damage 1, 6, 6.

 

// Constraints:

// 1 <= power.length <= 105
// 1 <= power[i] <= 109



// 🚀 Approach
// Sort the array to process spell damages in ascending order.
// Group identical values: If the current spell damage is the same as the previous one, accumulate its damage.
// Track previous compatible spells: Use a pointer prev to find the last index where the spell damage is at least 3 less than the current one (power[prev] + 2 < power[i]).
// Use dynamic programming: For each spell, store the maximum damage achievable up to that point in dp[i].
// Return the maximum value from the dp array.







class Solution {
    public long maximumTotalDamage(int[] power) {
        Arrays.sort(power);
        int n = power.length;
        long[] dp = new long[n];
        dp[0] = power[0];

        int prev = 0;
        long prevMaxDamage = 0;

        for (int i = 1; i < n; i++) {
            if (power[i] == power[i - 1]) dp[i] = dp[i - 1] + power[i];
            else {
                while(prev < i && power[prev] + 2 < power[i]) {
                    prevMaxDamage = Math.max(prevMaxDamage , dp[prev]);
                    prev++;
                }
                dp[i] = prevMaxDamage + power[i];
            }
        }
        long maxDamage = 0;
        for (long val : dp) maxDamage = Math.max(maxDamage , val);
        return maxDamage;
    }
}