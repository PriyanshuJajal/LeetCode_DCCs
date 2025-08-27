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
// We aim to find the longest diagonal path in a grid that starts from a cell with value 1 and alternates between values 1 → 2 → 0 → 2 → 0 → ..., allowing at most one 90° clockwise turn in direction.
// 1. Direction Setup:
//     Define four diagonal directions:
//     - Bottom-right (1, 1)
//     - Bottom-left (1, -1)
//     - Top-right (-1, 1)
//     - Top-left (-1, -1)
// 2. DFS Traversal:
//     From each cell with value 1, perform DFS in all four diagonal directions.
//         - Track the current direction, number of turns used (turned), and step count (step) to determine expected value.
//         - At each step, check if the cell matches the expected value based on the alternating pattern.

// 3. Clockwise Turn Logic:
//     If no turn has been used yet (turned == 0), allow a single clockwise turn using a helper function getClockwiseTurn(dir).
// 4. Result Aggregation:
//     For each valid starting cell and direction, compute the maximum path length and update the global result.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n , m;
    vector<vector<int>> grid;
    vector<pair<int,int>> directions = {{1 , 1} , {1 , -1} , {-1 , 1} , {-1 , -1}};
   
    int getClockwiseTurn(int dir) {
        if (dir == 0) return 1;
        if (dir == 1) return 3;
        if (dir == 2) return 0;
        if (dir == 3) return 2;
        return -1;
    }
    
    int dfs(int i , int j , int dir , int turned , int step) {
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        
        int expected = (step == 0) ? 1 : ((step % 2 == 1) ? 2 : 0);
        if (grid[i][j] != expected) return 0;
    
        int best = 1 + dfs(i + directions[dir].first, j + directions[dir].second, dir, turned, step + 1);
       
        if (!turned) {
            int newDir = getClockwiseTurn(dir);
            best = max(best, 1 + dfs(i + directions[newDir].first , j + directions[newDir].second , newDir , 1 , step + 1));
        }
        
        return best;
    }
    
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        this -> grid = grid;
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        res = max(res , dfs(i , j , dir , 0 , 0));
                    }
                }
            }
        }
        
        return res;
    }
};