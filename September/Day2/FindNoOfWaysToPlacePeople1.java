// LEETCODE 3025. Find the Number of Ways to Place People I

// You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].

// Count the number of pairs of points (A, B), where

// A is on the upper left side of B, and
// there are no other points in the rectangle (or line) they make (including the border).
// Return the count.

 

// Example 1:

// Input: points = [[1,1],[2,2],[3,3]]

// Output: 0

// Explanation:



// There is no way to choose A and B so A is on the upper left side of B.

// Example 2:

// Input: points = [[6,2],[4,4],[2,6]]

// Output: 2

// Explanation:



// The left one is the pair (points[1], points[0]), where points[1] is on the upper left side of points[0] and the rectangle is empty.
// The middle one is the pair (points[2], points[1]), same as the left one it is a valid pair.
// The right one is the pair (points[2], points[0]), where points[2] is on the upper left side of points[0], but points[1] is inside the rectangle so it's not a valid pair.
// Example 3:

// Input: points = [[3,1],[1,3],[1,1]]

// Output: 2

// Explanation:


// The left one is the pair (points[2], points[0]), where points[2] is on the upper left side of points[0] and there are no other points on the line they form. Note that it is a valid state when the two points form a line.
// The middle one is the pair (points[1], points[2]), it is a valid pair same as the left one.
// The right one is the pair (points[1], points[0]), it is not a valid pair as points[2] is on the border of the rectangle.
 

// Constraints:

// 2 <= n <= 50
// points[i].length == 2
// 0 <= points[i][0], points[i][1] <= 50
// All points[i] are distinct.


// 🚀 Approach
// Sort the points by:
//     Increasing x-coordinate.
//     For ties, decreasing y-coordinate (to prioritize higher points first).
// Iterate over each point i:
//     For each point j > i, check if points[j][1] <= points[i][1] (i.e., j is below or at same height).
//     Use a last variable to track the last accepted y-coordinate to avoid counting blocked rectangles.
//     If points[j][1] > last, it means this point is not blocked by any previously counted point, so we count it and update last.
// This greedy sweep avoids explicitly checking all intermediate points, making it efficient and elegant.



class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points , (a , b) -> {
            if (a[0] == b[0]) return b[1] - a[1];
            return a[0] - b[0];
        });

        int cntPairs = 0;
        for (int i = 0; i < points.length; i++) {
            int b = points[i][1] , last = -1;
            for (int j = i + 1; j < points.length; j++) {
                int a = points[j][1];
                if (a <= b && a > last) {
                    last = a;
                    cntPairs++;
                }
            }
        }
        return cntPairs;
    }
} 