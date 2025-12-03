// LEETCODE 3625. Count Number of Trapezoids II

// You are given a 2D integer array points where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

// Return the number of unique trapezoids that can be formed by choosing any four distinct points from points.

// A trapezoid is a convex quadrilateral with at least one pair of parallel sides. Two lines are parallel if and only if they have the same slope.

 

// Example 1:

// Input: points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]

// Output: 2

// Explanation:



// There are two distinct ways to pick four points that form a trapezoid:

// The points [-3,2], [2,3], [3,2], [2,-3] form one trapezoid.
// The points [2,3], [3,2], [3,0], [2,-3] form another trapezoid.
// Example 2:

// Input: points = [[0,0],[1,0],[0,1],[2,1]]

// Output: 1

// Explanation:



// There is only one trapezoid which can be formed.

 

// Constraints:

// 4 <= points.length <= 500
// –1000 <= xi, yi <= 1000
// All points are pairwise distinct.


// 🚀 Approach
// Pairwise line construction:
//     For every pair of points, compute the slope and intercept of the line passing through them.
//     Store these in a map slopeToIntercept to group lines by slope.
//     Also store slope values keyed by the midpoint of the pair in midToSlope to help detect duplicates.
// Counting trapezoids:
//     For each slope group, count how many distinct lines exist.
//     The number of trapezoids contributed by this slope group is the number of ways to pick two distinct lines with the same slope.
//     This is computed using a running sum technique: for each line count, add sum * cnt to the result, where sum is the cumulative count of previous lines.
// Avoiding duplicates:
//     Some trapezoids may be counted multiple times if they share midpoints.
//     To correct this, iterate over midToSlope and subtract duplicate counts using the same running sum technique.
// Final result:
//     After inclusion from slope groups and exclusion from midpoint groups, the result is the number of unique trapezoids.

// 🕛 Complexity
// Time complexity: O(n²)
// Space complexity: O(n²)













class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int INF = 1e9 + 7;
        unordered_map<float , vector<float>> slopeToIntercept;
        unordered_map<int , vector<float>> midToSlope;
        int res = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x1 - x2;
                int dy = y1 - y2;

                float k , b;
                if (x2 == x1) {
                    k = INF;
                    b = x1;
                }
                else {
                    k = (float)(y2 - y1) / (x2 - x1);
                    b = (float)(y1 * dx - x1 * dy) / dx;
                }

                int mid = (x1 + x2) * 10000 + (y1 + y2);
                slopeToIntercept[k].push_back(b);
                midToSlope[mid].push_back(k);
            }
        }

        for (auto& [_ , sti] : slopeToIntercept) {
            if (sti.size() == 1) continue;

            map<float , int> count;
            for (float b : sti) count[b]++; 

            int sum = 0;
            for (auto& [_ , cnt] : count) {
                res += (sum * cnt);
                sum += cnt;
            }
        }

        for (auto& [_ , mts] : midToSlope) {
            if (mts.size() == 1) continue;
            
            map<float , int> count;
            for (float k : mts) count[k]++;

            int sum = 0;
            for (auto& [_ , cnt] : count) {
                res -= (sum * cnt);
                sum += cnt;
            }
        }
        return res;
    }
};

