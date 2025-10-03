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
public:
    typedef pair<int , pair<int , int>> PP;
    vector<vector<int>> dirs = {{0 , -1} , {0 , 1} , {-1 , 0} , {1 , 0}};
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP , vector<PP> , greater<>> boundaryCells;
        vector<vector<bool>> vis(m , vector<bool>(n , false));

        for (int row = 0; row < m; row++) {
            for (int col : {0 , n - 1}) {
                boundaryCells.push({heightMap[row][col] , {row , col}});
                vis[row][col] = true;
            }
        }

        for (int col = 0; col < n; col++) {
            for (int row : {0 , m - 1}) {
                boundaryCells.push({heightMap[row][col] , {row , col}});
                vis[row][col] = true;
            }
        }

        int totalWater = 0;
        while(!boundaryCells.empty()) {
            PP p = boundaryCells.top();
            boundaryCells.pop();

            int ht = p.first;
            int i = p.second.first;
            int j = p.second.second;

            for (vector<int>& dir : dirs) {
                int di = i + dir[0];
                int dj = j + dir[1];

                if (di >= 0 && di < m && dj >= 0 && dj < n && !vis[di][dj]) {
                    totalWater += max(ht - heightMap[di][dj] , 0);

                    boundaryCells.push({max(ht , heightMap[di][dj]) , {di , dj}});
                    vis[di][dj] = true;
                }
            }
        }
        return totalWater;
    }
};