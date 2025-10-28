// LEETCODE 3354. Make Array Elements Equal to Zero

// You are given an integer array nums.

// Start by selecting a starting position curr such that nums[curr] == 0, and choose a movement direction of either left or right.

// After that, you repeat the following process:

// If curr is out of the range [0, n - 1], this process ends.
// If nums[curr] == 0, move in the current direction by incrementing curr if you are moving right, or decrementing curr if you are moving left.
// Else if nums[curr] > 0:
// Decrement nums[curr] by 1.
// Reverse your movement direction (left becomes right and vice versa).
// Take a step in your new direction.
// A selection of the initial position curr and movement direction is considered valid if every element in nums becomes 0 by the end of the process.

// Return the number of possible valid selections.



 

// Example 1:

// Input: nums = [1,0,2,0,3]

// Output: 2

// Explanation:

// The only possible valid selections are the following:

// Choose curr = 3, and a movement direction to the left.
// [1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,1,0,3] -> [1,0,1,0,3] -> [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,0,0,2] -> [1,0,0,0,2] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,0].
// Choose curr = 3, and a movement direction to the right.
// [1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,2,0,2] -> [1,0,2,0,2] -> [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,1,0,1] -> [1,0,1,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [0,0,0,0,0].
// Example 2:

// Input: nums = [2,3,4,0,4,1,0]

// Output: 0

// Explanation:

// There are no possible valid selections.

 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100
// There is at least one element i where nums[i] == 0.



// 🚀 Approach
// We compute the total sum of the array and maintain two running sums:
//     lSum: sum of elements to the left of the current index.
//     rSum: sum of elements to the right of the current index.
// For each index i where nums[i] == 0, we check:
//     If starting at i and moving right, then lSum - rSum must be in {0, 1}.
//     If starting at i and moving left, then rSum - lSum must be in {0, 1}.
// These conditions ensure that the number of direction reversals and steps taken will balance out to cover the entire array and reduce all values to zero.









class Solution {
    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int cnt = 0;
        int sum = 0;

        for (int num : nums) sum += num;
        int lSum = 0;
        int rSum = sum;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (lSum - rSum >= 0 && lSum - rSum <= 1) cnt++;
                if (rSum - lSum >= 0 && rSum - lSum <= 1) cnt++;
            }
            else {
                lSum += nums[i];
                rSum -= nums[i];
            }
        } 
        return cnt;
    }
}














