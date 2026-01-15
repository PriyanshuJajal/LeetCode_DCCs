// LEETCODE 2943. Maximize Area of Square Hole in Grid

// You are given the two integers, n and m and two integer arrays, hBars and vBars. The grid has n + 2 horizontal and m + 2 vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.

// You can remove some of the bars in hBars from horizontal bars and some of the bars in vBars from vertical bars. Note that other bars are fixed and cannot be removed.

// Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).

 

// Example 1:



// Input: n = 2, m = 1, hBars = [2,3], vBars = [2]

// Output: 4

// Explanation:

// The left image shows the initial grid formed by the bars. The horizontal bars are [1,2,3,4], and the vertical bars are [1,2,3].

// One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.

// Example 2:



// Input: n = 1, m = 1, hBars = [2], vBars = [2]

// Output: 4

// Explanation:

// To get the maximum square-shaped hole, we remove horizontal bar 2 and vertical bar 2.

// Example 3:



// Input: n = 2, m = 3, hBars = [2,3], vBars = [2,4]

// Output: 4

// Explanation:

// One way to get the maximum square-shaped hole is by removing horizontal bar 3, and vertical bar 4.

 

// Constraints:

// 1 <= n <= 109
// 1 <= m <= 109
// 1 <= hBars.length <= 100
// 2 <= hBars[i] <= n + 1
// 1 <= vBars.length <= 100
// 2 <= vBars[i] <= m + 1
// All values in hBars are distinct.
// All values in vBars are distinct


// 🚀 Approach
// Sort the bars: Sorting ensures we can easily check for consecutive bars.
// Find longest consecutive streaks:
//     Traverse through hBars and count the longest sequence of consecutive integers.
//     Do the same for vBars.
// Compute maximum gap:
//     The maximum consecutive streak in horizontal bars = hMax.
//     The maximum consecutive streak in vertical bars = vMax.
// Square side length:
//     The side length of the square hole = min(hMax , vMax) + 1.
//     +1 is added because the number of removed bars defines gaps between them, so the actual hole size is one larger.
// Return area = (side * side).

// 🕛 Complexity
// Time complexity: O(hlogh + vlogv)
// h = number of horizontal bars
// v = number of vertical bars

// Space complexity: O(1)









class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars) , end(hBars));
        sort(begin(vBars) , end(vBars));
        int hMax = 1 , vMax = 1;
        int hCurr = 1 , vCurr = 1;

        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) hCurr++;
            else hCurr = 1;

            hMax = max(hMax , hCurr);
        }

        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) vCurr++;
            else vCurr = 1;

            vMax = max(vMax , vCurr);
        }

        int side = min(vMax , hMax) + 1;
        return side * side;
    }
};