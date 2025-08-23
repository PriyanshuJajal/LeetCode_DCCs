// LEETCODE 3197. Find the Minimum Area to Cover All Ones II

// You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.

// Return the minimum possible sum of the area of these rectangles.

// Note that the rectangles are allowed to touch.

 

// Example 1:

// Input: grid = [[1,0,1],[1,1,1]]

// Output: 5

// Explanation:



// The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
// The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
// The 1 at (1, 1) is covered by a rectangle of area 1.
// Example 2:

// Input: grid = [[1,0,1,0],[0,1,0,1]]

// Output: 5

// Explanation:



// The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
// The 1 at (1, 1) is covered by a rectangle of area 1.
// The 1 at (1, 3) is covered by a rectangle of area 1.
 

// Constraints:

// 1 <= grid.length, grid[i].length <= 30
// grid[i][j] is either 0 or 1.
// The input is generated such that there are at least three 1's in grid.


// 🚀 Approach
// Horizontal Splits:
//     We try all combinations of two horizontal cuts that divide the grid into three horizontal strips.
// Vertical Splits:
//     We try all combinations of two vertical cuts that divide the grid into three vertical strips.
// Mixed Splits
//     We try combinations of one horizontal and one vertical cut to form L-shaped or corner-based partitions.
// For each configuration, we:
//     Use getArea() to compute the bounding box area of 1s in each region.
//     Skip regions with no 1s by returning a large value (LLONG_MAX / 3).
//     Track the minimum total area across all valid configurations.
//     The getArea() function scans the subgrid and computes the bounding box of 1s using min/max row and column indices.



class Solution {
public:
    long long getArea(vector<vector<int>>& grid , int r1 , int c1 , int r2 , int c2) {
        int minR = INT_MAX , minC = INT_MAX;
        int maxR = INT_MIN , maxC = INT_MIN;
        bool found = false;

        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j] == 1) {
                    found = true;
                    minR = min(minR , i);
                    maxR = max(maxR , i);
                    minC = min(minC , j);
                    maxC = max(maxC , j);
                }
            }
        }

        if (!found) return LLONG_MAX / 3;
        return (long long)(maxR - minR + 1) * (maxC - minC + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long minTotalArea = LLONG_MAX;

        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m - 1; j++) {
                long long a1 = getArea(grid , 0 , 0 , i , n - 1);
                long long a2 = getArea(grid , i + 1 , 0 , j , n - 1);
                long long a3 = getArea(grid , j + 1 , 0 , m - 1 , n - 1);
                minTotalArea = min(minTotalArea , a1 + a2 + a3);
            }
        }   

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                long long a1 = getArea(grid , 0 , 0 , m - 1 , i);
                long long a2 = getArea(grid , 0 , i + 1 , m - 1 , j);
                long long a3 = getArea(grid , 0 , j + 1 , m - 1 , n - 1);
                minTotalArea = min(minTotalArea , a1 + a2 + a3);
            }
        }
        
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                long long a1 = getArea(grid , 0 , 0 , i , j);
                long long a2 = getArea(grid , 0 , j + 1 , i , n - 1);
                long long a3 = getArea(grid , i + 1 , 0 , m - 1 , n - 1);
                minTotalArea = min(minTotalArea , a1 + a2 + a3);

                a1 = getArea(grid , 0 , 0 , i , n - 1);
                a2 = getArea(grid , i + 1 , 0 , m - 1 , j);
                a3 = getArea(grid , i + 1 , j + 1 , m - 1 , n - 1);
                minTotalArea = min(minTotalArea , a1 + a2 + a3);

                a1 = getArea(grid , 0 , 0 , i , j);
                a2 = getArea(grid , i + 1 , 0 , m - 1 , j);
                a3 = getArea(grid , 0 , j + 1 , m - 1 , n - 1);
                minTotalArea = min(minTotalArea , a1 + a2 + a3);

                a1 = getArea(grid , 0 , 0 , m - 1 , j);
                a2 = getArea(grid , 0 , j + 1 , i , n - 1);
                a3 = getArea(grid , i + 1 , j + 1 , m - 1 , n - 1);   
                minTotalArea = min(minTotalArea , a1 + a2 + a3);
            }
        }

        return (int)minTotalArea;
    }
};