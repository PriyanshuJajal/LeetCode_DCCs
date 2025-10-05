// LEETCODE 417. Pacific Atlantic Water Flow

// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

// Example 1:


// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
// [0,4]: [0,4] -> Pacific Ocean 
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean 
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean 
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
// Example 2:

// Input: heights = [[1]]
// Output: [[0,0]]
// Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
 

// Constraints:

// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 105


// 🚀 Approach
// Initialize two boolean grids pac and atl to track cells reachable from the Pacific and Atlantic oceans.
// DFS from Pacific borders:
//     Top row (row 0)
//     Left column (col 0)
// DFS from Atlantic borders:
//     Bottom row (row rows - 1)
//     Right column (col cols - 1)
// In each DFS, only move to neighboring cells with height ≥ current cell.
// After DFS traversal, collect all cells that are marked true in both pac and atl.





class Solution {
    private int rows , cols;
    private final int[][] dirs = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};

    private void dfs(int r , int c , int[][] heights , boolean[][] vis , int prevHt) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || vis[r][c] || heights[r][c] < prevHt) return;

        vis[r][c] = true;
        for (int[] dir : dirs) {
            dfs(r + dir[0] , c + dir[1] , heights , vis , heights[r][c]);
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        rows = heights.length;
        cols = heights[0].length;
        boolean[][] pac = new boolean[rows][cols];
        boolean[][] atl = new boolean[rows][cols];

        for (int c = 0; c < cols; c++) {
            dfs(0 , c , heights , pac , heights[0][c]);
            dfs(rows - 1 , c , heights , atl , heights[rows - 1][c]);
        }

        for (int r = 0; r < rows; r++) {
            dfs(r , 0 , heights , pac , heights[r][0]);
            dfs(r , cols - 1 , heights , atl , heights[r][cols - 1]);
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac[r][c] && atl[r][c]) {
                    res.add(Arrays.asList(r , c));
                }
            }
        }
        return res;
    }
}
