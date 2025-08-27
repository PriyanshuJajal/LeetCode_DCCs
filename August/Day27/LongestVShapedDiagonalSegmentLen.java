// LEETCODE 3459. Length of Longest V-Shaped Diagonal Segment

// You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.

// A V-shaped diagonal segment is defined as:

// The segment starts with 1.
// The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
// The segment:
// Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
// Continues the sequence in the same diagonal direction.
// Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.


// Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.

 

// Example 1:

// Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

// Output: 5

// Explanation:



// The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at (2,4), and continues as (3,3) → (4,2).

// Example 2:

// Input: grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

// Output: 4

// Explanation:



// The longest V-shaped diagonal segment has a length of 4 and follows these coordinates: (2,3) → (3,2), takes a 90-degree clockwise turn at (3,2), and continues as (2,1) → (1,0).

// Example 3:

// Input: grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]

// Output: 5

// Explanation:



// The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,0) → (1,1) → (2,2) → (3,3) → (4,4).

// Example 4:

// Input: grid = [[1]]

// Output: 1

// Explanation:

// The longest V-shaped diagonal segment has a length of 1 and follows these coordinates: (0,0).

 

// Constraints:

// n == grid.length
// m == grid[i].length
// 1 <= n, m <= 500
// grid[i][j] is either 0, 1 or 2.


// Approach...
// We aim to find the longest diagonal path in a grid that starts from a cell with value 1 and alternates between values 1 → 2 → 1 → 2 → ..., allowing at most one 90° clockwise turn in direction.
// 🔧 Key Concepts:
// - Diagonal Directions: We define four diagonals:
// ↘ (1,1), ↙ (1,-1), ↖ (-1,-1), ↗ (-1,1)
// - Alternating Pattern: The path alternates between values 1 and 2.
// - Single Turn Allowed: At most one 90° clockwise turn is permitted during traversal.


//  DFS Traversal:
// - From each cell with value 1, we initiate DFS in all four diagonal directions.
// - The DFS function tracks:
// - Current position (i, j)
// - Direction index dir
// - Whether a turn has already been used (has90DegTurned)
// - The expected value at the next step (target)
// - If the next cell matches the expected value, we continue in the same direction.
// - If a turn is still allowed, we also explore the next direction (dir + 1) % 4.


// Memoization:
// - We use a 4D memo table memo[i][j][dir][turned] to cache results and avoid recomputation.
// - turned is encoded as 0 or 1 depending on whether the turn has been used.

// Result Aggregation:
// - For each valid starting cell and direction, we compute the longest path and update the global maximum.






class Solution {
    private static final int[][] dirs = {{1 , 1} , {1 , -1} , {-1 , -1} , {-1 , 1}};
    private int[][][][] memo;
    private int[][] grid;
    private int m , n;

    public int lenOfVDiagonal(int[][] grid) {
        this.grid = grid;
        this.m = grid.length;
        this.n = grid[0].length;
        this.memo = new int[m][n][4][2];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    Arrays.fill(memo[i][j][k] , -1);
                }
            }
        }    
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        res = Math.max(res , 1 + dfs(i , j , dir , true , 2));
                    }
                }
            }
        }
        return res;
    }

    private int dfs(int i , int j , int dir , boolean has90DegTurned , int target) {
        int x = i + dirs[dir][0] , y = j + dirs[dir][1];

        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != target) return 0;
        int turnedInt = has90DegTurned ? 1 : 0;

        if (memo[x][y][dir][turnedInt] != -1) return memo[x][y][dir][turnedInt];

        int maxLen = dfs(x , y , dir , has90DegTurned , 2 - target);
        if (has90DegTurned) maxLen = Math.max(maxLen , dfs(x , y , (dir + 1) % 4 , false , 2 - target));

        return memo[x][y][dir][turnedInt] = maxLen + 1;
    }
}