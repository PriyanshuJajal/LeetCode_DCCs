// LEETCODE 3623. Count Number of Trapezoids I

// You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

// A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

// Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

// Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]

// Output: 3

// Explanation:



// There are three distinct ways to pick four points that form a horizontal trapezoid:

// Using points [1,0], [2,0], [3,2], and [2,2].
// Using points [2,0], [3,0], [3,2], and [2,2].
// Using points [1,0], [3,0], [3,2], and [2,2].
// Example 2:

// Input: points = [[0,0],[1,0],[0,1],[2,1]]

// Output: 1

// Explanation:



// There is only one horizontal trapezoid that can be formed.

 

// Constraints:

// 4 <= points.length <= 105
// –108 <= xi, yi <= 108
// All points are pairwise distinct.



// 🚀 Approach
// Group points by y-coordinate:
//     Since horizontal lines are defined by equal y values, we count how many points lie on each y.
// Compute pair counts per line:
//     For each line with cnt points, the number of ways to choose 2 points is: cnt * (cnt - 1) / 2
//     Store these values in a list pairCnt.
// Efficiently sum products across lines:
//     We want: ∑ pairCnt[i] * pairCnt[j] (i < j)
//     Instead of nested loops, maintain a running sum of previous counts.
//     For each new count, add sum * count to total.
//     This ensures every pair is counted exactly once.
// Modulo arithmetic:
//     Since results can be large, every operation is taken modulo 10^9 + 7.

// 🕛 Complexity
// Time complexity: O(n)

// Space complexity: O(k)

// k = number of distinct y values
// Hash map for frequencies → O(k).
// Pair counts list → O(k).













class Solution {
public:
    const int M = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int , int> freq;

        for (auto& p : points) {
            freq[p[1]]++;
        }

        vector<long long> pairCnt;

        for (auto& [y , cnt] : freq) {
            if (cnt >= 2) {
                pairCnt.push_back(1LL * cnt * (cnt - 1) / 2);
            }
        }

        long long total = 0 , sum = 0;

        for (auto count : pairCnt) {
            total = (total + sum * count % M) % M;
            sum = (sum + count) % M;
        }
        return total;
    }
};
