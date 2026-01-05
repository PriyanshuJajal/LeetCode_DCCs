// LEETCODE 1975. Maximum Matrix Sum

// You are given an n x n integer matrix. You can do the following operation any number of times:

// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.

// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

 

// Example 1:


// Input: matrix = [[1,-1],[-1,1]]
// Output: 4
// Explanation: We can follow the following steps to reach sum equals 4:
// - Multiply the 2 elements in the first row by -1.
// - Multiply the 2 elements in the first column by -1.
// Example 2:


// Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
// Output: 16
// Explanation: We can follow the following step to reach sum equals 16:
// - Multiply the 2 last elements in the second row by -1.
 

// Constraints:

// n == matrix.length == matrix[i].length
// 2 <= n <= 250
// -105 <= matrix[i][j] <= 105





// 🚀 Approach
// Traverse the entire matrix.
//     Count how many elements are negative (cnt).
//     Compute the sum of absolute values of all elements (sum).
//     Track the smallest absolute value (minEl).
// If the number of negative elements is even, we can flip all negatives to positives.
//     The maximum sum is simply sum.
// If the number of negative elements is odd, one element must remain negative.
//     To minimize the loss, we leave the element with the smallest absolute value negative.
//     So the maximum sum is sum - 2 * minEl.

// 🕛 Complexity
// Time complexity: O(n²)
// Space complexity: O(1)









class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int n = matrix.length;
        long sum = 0;
        int cnt = 0;
        int minEl = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) cnt++;
                sum += Math.abs(matrix[i][j]);
                minEl = Math.min(minEl, Math.abs(matrix[i][j]));
            }
        }

        if (cnt % 2 == 0) {
            return sum;
        } else {
            return sum - 2L * minEl;
        }
    }
}