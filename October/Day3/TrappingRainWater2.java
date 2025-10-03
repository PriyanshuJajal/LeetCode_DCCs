// LEETCODE 407. Trapping Rain Water II

// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

// Example 1:


// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.
// Example 2:


// Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
// Output: 10
 

// Constraints:

// m == heightMap.length
// n == heightMap[i].length
// 1 <= m, n <= 200
// 0 <= heightMap[i][j] <= 2 * 104



// 🚀 Approach
// Push all boundary cells into a min-heap (priority queue) based on their height.
// Mark them as visited.
    // While the heap is not empty:
    // Pop the cell with the lowest height.
    // For each unvisited neighbor:
        // If the neighbor is lower, water can be trapped: max(0, currentHeight - neighborHeight).
        // Push the neighbor into the heap with updated height: max(currentHeight, neighborHeight).
        // Mark it visited.
// This ensures that we always expand from the lowest boundary inward, maintaining the correct water level.





class Solution {
    private static final int[][] dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    public int trapRainWater(int[][] heightMap) {
        int m = heightMap.length;
        int n = heightMap[0].length;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        boolean[][] vis = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            pq.offer(new int[] {heightMap[i][0] , i , 0});
            pq.offer(new int[] {heightMap[i][n - 1] , i , n - 1});
            vis[i][0] = true;
            vis[i][n - 1] = true;
        }

        for (int j = 0; j < n; j++) {
            pq.offer(new int[] {heightMap[0][j] , 0 , j});
            pq.offer(new int[] {heightMap[m - 1][j] , m - 1 , j});
            vis[0][j] = true;
            vis[m - 1][j] = true;
        }

        int totalWater = 0;

        while (!pq.isEmpty()) {
            int[] cell = pq.poll();
            int height = cell[0];
            int x = cell[1];
            int y = cell[2];

            for (int[] dir : dirs) {
                int dx = x + dir[0];
                int dy = y + dir[1];

                if (dx >= 0 && dx < m && dy >= 0 && dy < n && !vis[dx][dy]) {
                    vis[dx][dy] = true;
                    totalWater += Math.max(0 , height - heightMap[dx][dy]);
                    pq.offer(new int[] {Math.max(height , heightMap[dx][dy]) , dx , dy});
                }
            }
        }
        return totalWater;
    }
}