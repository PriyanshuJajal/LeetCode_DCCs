// LEETCODE 2033. Minimum Operations to Make a Uni-Value Grid

// You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

// A uni-value grid is a grid where all the elements of it are equal.

// Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

 

// Example 1:


// Input: grid = [[2,4],[6,8]], x = 2
// Output: 4
// Explanation: We can make every element equal to 4 by doing the following: 
// - Add x to 2 once.
// - Subtract x from 6 once.
// - Subtract x from 8 twice.
// A total of 4 operations were used.
// Example 2:


// Input: grid = [[1,5],[2,3]], x = 1
// Output: 5
// Explanation: We can make every element equal to 3.
// Example 3:


// Input: grid = [[1,2],[3,4]], x = 2
// Output: -1
// Explanation: It is impossible to make every element equal.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 105
// 1 <= m * n <= 105
// 1 <= x, grid[i][j] <= 104


// 🚀 Approach
// Flatten the 2D grid into a 1D array.
// Sort the array to easily find the median.
// Choose the median as the target value.
// For each number in the array:
//     Compute the difference with the median.
//     If the difference is not divisible by x, return -1 (impossible).
//     Otherwise, add diff / x to the total operations.
// Return the total operations.

// 🕛 Complexity
// Time complexity: O(mn * log(m * n))
// Space complexity: O(mn)



class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (auto& row : grid) {
            for (int val : row) nums.push_back(val);
        }

        sort(begin(nums) , end(nums));
        int median = nums[nums.size() / 2];
        int minOps = 0;

        for (int num : nums) {
            int diff = abs(num - median);
            if (diff % x != 0) return -1;
            minOps += diff / x;
        }
        return minOps;
    }
};