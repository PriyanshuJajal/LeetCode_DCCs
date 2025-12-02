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
    private static final int M = 1_000_000_007;
    public int countTrapezoids(int[][] points) {
        Map<Integer , Integer> freq = new HashMap<>();
        for (int[] p : points) {
            freq.put(p[1] , freq.getOrDefault(p[1] , 0) + 1);
        }

        List<Long> pairCnt = new ArrayList<>();
        for (Map.Entry<Integer , Integer> e : freq.entrySet()) {
            int cnt = e.getValue();
            if (cnt >= 2) {
                long val = (long) cnt * (cnt - 1) / 2;
                pairCnt.add(val);
            }
        }

        long total = 0;
        long sum = 0;
        for (long count : pairCnt) {
            total = (total + (sum * count) % M) % M;
            sum = (sum + count) % M;
        }
        return (int)total;
    }
}
