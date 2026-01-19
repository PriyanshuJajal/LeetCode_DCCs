// LEETCODE 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

// Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

 

// Example 1:


// Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
// Output: 2
// Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
// Example 2:

// Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
// Output: 0
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 300
// 0 <= mat[i][j] <= 104
// 0 <= threshold <= 105



// 🚀 Approach
//     Prefix Sum Matrix
//     Build a 2D prefix sum pref[i][j] that stores the sum of all elements in the rectangle (0,0) to (i,j).
//     This allows us to compute the sum of any submatrix (r1,c1) to (r2,c2) in O(1) time.
// Check Function
//     For a given side length side, iterate over all possible top-left corners (i,j) of squares of that size.
//     Use the prefix sum to compute the square’s sum.
//     If any square of size side has sum ≤ threshold, return true.
// Binary Search
//     Search between 1 and min(m , n) for the largest valid side length.
//     If check(mid) is true, move right (l = mid + 1) to try larger squares.
//     Otherwise, move left (h = mid - 1).
//     Keep track of the maximum valid side length.

// 🕛 Complexity
// Time complexity: O(m * n * log(min(m , n)))
// Space complexity: O(m * n)









class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;

        int[][] pref = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i][j] = mat[i][j]
                        + (i > 0 ? pref[i - 1][j] : 0)
                        + (j > 0 ? pref[i][j - 1] : 0)
                        - (i > 0 && j > 0 ? pref[i - 1][j - 1] : 0);
            }
        }

        java.util.function.IntQuadFunction sumOfSquare = (r1, c1, r2, c2) -> {
            int sum = pref[r2][c2];
            if (r1 > 0) sum -= pref[r1 - 1][c2];
            if (c1 > 0) sum -= pref[r2][c1 - 1];
            if (r1 > 0 && c1 > 0) sum += pref[r1 - 1][c1 - 1];
            return sum;
        };

        java.util.function.IntPredicate check = side -> {
            for (int i = 0; i + side - 1 < m; i++) {
                for (int j = 0; j + side - 1 < n; j++) {
                    if (sumOfSquare.apply(i, j, i + side - 1, j + side - 1) <= threshold) {
                        return true;
                    }
                }
            }
            return false;
        };

        int l = 1, h = Math.min(m, n);
        int maxSide = 0;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check.test(mid)) {
                maxSide = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return maxSide;
    }
}

@FunctionalInterface
interface IntQuadFunction {
    int apply(int a, int b, int c, int d);
}