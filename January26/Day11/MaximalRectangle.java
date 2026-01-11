// LEETCODE 85. Maximal Rectangle

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.



// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= rows, cols <= 200
// matrix[i][j] is '0' or '1'.



// 🚀 Approach
// Histogram Transformation:
//     Convert each row into a histogram of heights.
//     If matrix[r][c] == '1', increment heights[c] by 1.
//     If matrix[r][c] == '0', reset heights[c] = 0.
// Largest Rectangle in Histogram:
//     For each histogram (row), calculate the largest rectangle using the Next Smaller to Left (NSL) and Next Smaller to Right (NSR) arrays.
//     NSL gives the nearest smaller element to the left of each bar.
//     NSR gives the nearest smaller element to the right of each bar.
//     The width of the rectangle for each bar = NSR[i] - NSL[i] - 1.
//     Area = width[i] * heights[i].
// Iterate Over Rows:
//     Start with the first row as the initial histogram.
//     For each subsequent row, update the histogram and compute the largest rectangle.
//     Keep track of the maximum area encountered.

// 🕛 Complexity
// m = number of rows
// n = number of columns

// Time complexity: O(m * n)
// Space complexity: O(n)









import java.util.*;

class Solution {
    // NSR -> Next Smaller to Right
    public int[] getNSR(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int n = heights.length;
        int[] NSR = new int[n];

        for (int i = n - 1; i >= 0; i--) {
            if (st.isEmpty()) NSR[i] = n;
            else {
                while (!st.isEmpty() && heights[st.peek()] >= heights[i]) {
                    st.pop();
                }
                if (st.isEmpty()) NSR[i] = n;
                else NSR[i] = st.peek();
            }
            st.push(i);
        }
        return NSR;
    }

    // NSL -> Next Smaller to Left
    public int[] getNSL(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int n = heights.length;
        int[] NSL = new int[n];

        for (int i = 0; i < n; i++) {
            if (st.isEmpty()) NSL[i] = -1;
            else {
                while (!st.isEmpty() && heights[st.peek()] >= heights[i]) {
                    st.pop();
                }
                if (st.isEmpty()) NSL[i] = -1;
                else NSL[i] = st.peek();
            }
            st.push(i);
        }
        return NSL;
    }

    public int findMaxArea(int[] heights) {
        int[] NSR = getNSR(heights);
        int[] NSL = getNSL(heights);

        int n = heights.length;
        int[] width = new int[n];

        for (int i = 0; i < n; i++) {
            width[i] = NSR[i] - NSL[i] - 1;
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = width[i] * heights[i];
            maxArea = Math.max(maxArea, area);
        }
        return maxArea;
    }

    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int[] heights = new int[n];

        // First row as histogram
        for (int i = 0; i < n; i++) {
            heights[i] = (matrix[0][i] == '1') ? 1 : 0;
        }

        int maxArea = findMaxArea(heights);

        // Process remaining rows
        for (int r = 1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == '0') {
                    heights[c] = 0;
                } else {
                    heights[c] += 1;
                }
            }
            maxArea = Math.max(maxArea, findMaxArea(heights));
        }
        return maxArea;
    }
}