// LEETCODE 3531. Count Covered Buildings

// You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].

// A building is covered if there is at least one building in all four directions: left, right, above, and below.

// Return the number of covered buildings.

 

// Example 1:



// Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]

// Output: 1

// Explanation:

// Only building [2,2] is covered as it has at least one building:
// above ([1,2])
// below ([3,2])
// left ([2,1])
// right ([2,3])
// Thus, the count of covered buildings is 1.
// Example 2:



// Input: n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]

// Output: 0

// Explanation:

// No building has at least one building in all four directions.
// Example 3:



// Input: n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]

// Output: 1

// Explanation:

// Only building [3,3] is covered as it has at least one building:
// above ([1,3])
// below ([5,3])
// left ([3,2])
// right ([3,5])
// Thus, the count of covered buildings is 1.
 

// Constraints:

// 2 <= n <= 105
// 1 <= buildings.length <= 105 
// buildings[i] = [x, y]
// 1 <= x, y <= n
// All coordinates of buildings are unique.



// 🚀 Approach
// Initialize four arrays:
//     minCol[x] → smallest column index in row x.
//     maxCol[x] → largest column index in row x.
//     minRow[y] → smallest row index in column y.
//     maxRow[y] → largest row index in column y.
// Traverse all buildings and update these arrays.
// For each building (x, y), check:
//     y > minCol[x] → has a left neighbor.
//     y < maxCol[x] → has a right neighbor.
//     x > minRow[y] → has an upper neighbor.
//     x < maxRow[y] → has a lower neighbor.
// If all four conditions are true, increment the count.


// 🕛 Complexity
// Time complexity: O(m)
// m = buildings.size()

// Space complexity: O(n)













import java.util.*;

class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        int[] minCol = new int[n + 1];
        int[] maxCol = new int[n + 1];
        int[] minRow = new int[n + 1];
        int[] maxRow = new int[n + 1];

        // Initialize arrays
        Arrays.fill(minCol, n + 1);
        Arrays.fill(minRow, n + 1);
        Arrays.fill(maxCol, 0);
        Arrays.fill(maxRow, 0);

        // Process buildings
        for (int[] b : buildings) {
            int x = b[0];
            int y = b[1];

            if (y < minCol[x]) minCol[x] = y;
            if (y > maxCol[x]) maxCol[x] = y;

            if (x < minRow[y]) minRow[y] = x;
            if (x > maxRow[y]) maxRow[y] = x;
        }

        int cnt = 0;
        for (int[] b : buildings) {
            int x = b[0];
            int y = b[1];

            boolean left = (y > minCol[x]);
            boolean right = (y < maxCol[x]);
            boolean up = (x > minRow[y]);
            boolean down = (x < maxRow[y]);

            if (left && right && up && down) cnt++;
        }

        return cnt;
    }
}