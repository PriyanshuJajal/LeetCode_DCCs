// LEETCODE 120. Triangle

// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
 

// Constraints:

// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104



// 🚀 Approach
// Start from the second-last row and move upward.
// For each element, add the minimum of its two children from the row below.
// This way, each element becomes the minimum path sum from that point downward.
// The top element will eventually hold the overall minimum path sum.




class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        for (int i = n - 2; i >= 0; i--) {
            List<Integer> currRow = triangle.get(i);
            List<Integer> belowRow = triangle.get(i + 1);

            for (int j = 0; j < currRow.size(); j++) {
                int min = Math.min(belowRow.get(j) , belowRow.get(j + 1));
                currRow.set(j , currRow.get(j) + min); 
            }
        }
        return triangle.get(0).get(0);
    }
}