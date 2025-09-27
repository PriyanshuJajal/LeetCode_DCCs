// LEETCODE 812. Largest Triangle Area

// Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:


// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2.00000
// Explanation: The five points are shown in the above figure. The red triangle is the largest.
// Example 2:

// Input: points = [[1,0],[0,0],[0,1]]
// Output: 0.50000
 

// Constraints:

// 3 <= points.length <= 50
// -50 <= xi, yi <= 50
// All the given points are unique.



// 🚀 Approach
// Iterate over all unique triplets of points using three nested loops.
// For each triplet, calculate the area using the shoelace formula (also known as the determinant method):
// Area = 0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))
// Track the maximum area encountered during iteration.
// Return the maximum area found.





class Solution {
    public double largestTriangleArea(int[][] points) {
        int n = points.length;
        double maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                  int x1 = points[i][0];
                  int x2 = points[j][0];
                  int x3 = points[k][0];

                  int y1 = points[i][1];
                  int y2 = points[j][1];
                  int y3 = points[k][1];


                  double area = Math.abs(0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
                  maxArea = Math.max(maxArea , area);
                }
            }
        }
        return maxArea;
    }
}