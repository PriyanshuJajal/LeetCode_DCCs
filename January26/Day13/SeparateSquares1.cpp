// LEETCODE 3453. Separate Squares I

// You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

// Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.

// Answers within 10-5 of the actual answer will be accepted.

// Note: Squares may overlap. Overlapping areas should be counted multiple times.

 

// Example 1:

// Input: squares = [[0,0,1],[2,2,1]]

// Output: 1.00000

// Explanation:



// Any horizontal line between y = 1 and y = 2 will have 1 square unit above it and 1 square unit below it. The lowest option is 1.

// Example 2:

// Input: squares = [[0,0,2],[1,1,1]]

// Output: 1.16667

// Explanation:



// The areas are:

// Below the line: 7/6 * 2 (Red) + 1/6 (Blue) = 15/6 = 2.5.
// Above the line: 5/6 * 2 (Red) + 5/6 (Blue) = 15/6 = 2.5.
// Since the areas above and below the line are equal, the output is 7/6 = 1.16667.

 

// Constraints:

// 1 <= squares.length <= 5 * 104
// squares[i] = [xi, yi, li]
// squares[i].length == 3
// 0 <= xi, yi <= 109
// 1 <= li <= 109
// The total area of all the squares will not exceed 1012.


// 🚀 Approach
// Preprocessing
//     Compute the total area of all squares.
//     Find the minimum and maximum y‑coordinates covered by the squares (this gives the search range).
// Binary Search
//     Perform binary search on the y‑coordinate between l (lowest y) and h (highest y).
//     For each midpoint mid, calculate the area of all squares that lies below mid.
//         If mid is above the top of a square, add its full area.
//         If mid is between the bottom and top of a square, add the partial area (mid - y) * side length.
//     Compare this accumulated area with half of the total area.
//         If below area ≥ half, move the search range upward.
//         Otherwise, move downward.
// Stopping Condition
//     Continue until the difference between h and l is very small (precision threshold, e.g. 1e-5).
//     Return the final mid as the dividing y‑coordinate.
    
// 🕛 Complexity
// Time complexity: O(n * log(range))
// range = max ( i.e. y + side) - min y

// Space complexity: O(1)









class Solution {
public:
    bool check(vector<vector<int>>& squares , double mid , double total) {
        double belowArea = 0;
        for (auto& square : squares) {
            double y = square[1];
            double l = square[2];

            double belowY = y;
            double topY = y + l;

            if (mid >= topY) belowArea += l * l;
            else if (mid > belowY) belowArea += (mid - belowY) * l;
        }

        return belowArea >= (total / 2.0);
    }

    double separateSquares(vector<vector<int>>& squares) {
        double l = INT_MAX;
        double h = INT_MIN;
        double total = 0.00000;

        for (auto& square : squares) {
            double x = square[0];
            double y = square[1];
            double len = square[2];

            total += len * len;

            l = min(l , y);
            h = max(h , y + len);
        }

        double yCoord = 0.00000;
        while(h - l > 1e-5) {
            double mid = l + (h - l) / 2;
            yCoord = mid;

            if (check(squares , mid , total)) h = mid;
            else l = mid;
        }
        return yCoord;
    }
};