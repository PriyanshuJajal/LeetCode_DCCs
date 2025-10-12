// LEETCODE 3539. Find Sum of Array Product of Magical Sequences

// You are given two integers, m and k, and an integer array nums.

// A sequence of integers seq is called magical if:
// seq has a size of m.
// 0 <= seq[i] < nums.length
// The binary representation of 2seq[0] + 2seq[1] + ... + 2seq[m - 1] has k set bits.
// The array product of this sequence is defined as prod(seq) = (nums[seq[0]] * nums[seq[1]] * ... * nums[seq[m - 1]]).

// Return the sum of the array products for all valid magical sequences.

// Since the answer may be large, return it modulo 109 + 7.

// A set bit refers to a bit in the binary representation of a number that has a value of 1.

 

// Example 1:

// Input: m = 5, k = 5, nums = [1,10,100,10000,1000000]

// Output: 991600007

// Explanation:

// All permutations of [0, 1, 2, 3, 4] are magical sequences, each with an array product of 1013.

// Example 2:

// Input: m = 2, k = 2, nums = [5,4,3,2,1]

// Output: 170

// Explanation:

// The magical sequences are [0, 1], [0, 2], [0, 3], [0, 4], [1, 0], [1, 2], [1, 3], [1, 4], [2, 0], [2, 1], [2, 3], [2, 4], [3, 0], [3, 1], [3, 2], [3, 4], [4, 0], [4, 1], [4, 2], and [4, 3].

// Example 3:

// Input: m = 1, k = 1, nums = [28]

// Output: 28

// Explanation:

// The only magical sequence is [0].

 

// Constraints:

// 1 <= k <= m <= 30
// 1 <= nums.length <= 50
// 1 <= nums[i] <= 108



// 🚀 Approach
// Pascal's Triangle Precomputation (pascal):

// Precompute binomial coefficients C[i][j] for all i ≤ 30.
// Used to count how many ways we can choose f elements from m.
// Recursive DFS (dfs):

// Parameters:
//     m: remaining elements to pick
//     k: remaining set bits needed
//     i: current index in nums
//     flag: bitmask representing current sum of powers of 2
// Base cases:
//     If m < 0, k < 0, or m + popcount(flag) < k → invalid
//     If m == 0 → check if popcount(flag) == k
//     If i >= nums.length → no more choices
// Memoization:
//     Store results in dp[m][k][i][flag] to avoid recomputation.
// For each possible count f from 0 to m:
//     Compute permutations using C[m][f] * nums[i]^f
//     Update flag and shift to simulate bitmask propagation
//     Check if least significant bit is set
//     Recurse to next index

// Main Function (magicalSum):
//     Initializes Pascal’s triangle and memoization table
//     Starts DFS from index 0 with flag = 0







class Solution {    
    static final int MOD = (int)1e9 + 7;
    static int[][] C = new int[31][31];
    static int[][][][] dp = new int[31][31][50][31];

    int m, k, n;

    void pascal() {
        if (C[0][0] == 1) return;
        for (int i = 1; i <= 30; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j <= i / 2; j++) {
                int Cij = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] = C[i][i - j] = Cij;
            }
        }
    }

    int popcount(int x) {
        return Integer.bitCount(x);
    }

    int dfs(int m, int k, int i, int flag, int[] nums) {
        int bz = popcount(flag);
        if (m < 0 || k < 0 || m + bz < k) return 0;
        if (m == 0) return (k == bz) ? 1 : 0;
        if (i >= n) return 0;

        if (dp[m][k][i][flag] != -1) return dp[m][k][i][flag];

        long res = 0;
        long powX = 1;
        int x = nums[i];

        for (int f = 0; f <= m; f++) { 
            long perm = (1L * C[m][f] * powX) % MOD;

            int newFlag = flag + f;
            int nextFlag = newFlag >> 1;
            boolean bitSet = (newFlag & 1) != 0;

            res = (res + perm * dfs(m - f , k - (bitSet ? 1 : 0) , i + 1 , nextFlag , nums)) % MOD;
            powX = (powX * x) % MOD;
        }

        return dp[m][k][i][flag] = (int) res;
    }


    public int magicalSum(int m, int k, int[] nums) {
        pascal();
        this.m = m;
        this.k = k;
        this.n = nums.length;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= m; j++) {
                for (int s = 0; s < n; s++) {
                    Arrays.fill(dp[i][j][s] , -1);
                }
            }
        }
        return dfs(m , k , 0 , 0 , nums);    
    }
}
