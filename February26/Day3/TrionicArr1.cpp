// LEETCODE 3637. Trionic Array I

// You are given an integer array nums of length n.

// An array is trionic if there exist indices 0 < p < q < n − 1 such that:

// nums[0...p] is strictly increasing,
// nums[p...q] is strictly decreasing,
// nums[q...n − 1] is strictly increasing.
// Return true if nums is trionic, otherwise return false.

 

// Example 1:

// Input: nums = [1,3,5,4,2,6]

// Output: true

// Explanation:

// Pick p = 2, q = 4:

// nums[0...2] = [1, 3, 5] is strictly increasing (1 < 3 < 5).
// nums[2...4] = [5, 4, 2] is strictly decreasing (5 > 4 > 2).
// nums[4...5] = [2, 6] is strictly increasing (2 < 6).
// Example 2:

// Input: nums = [2,1,3]

// Output: false

// Explanation:

// There is no way to pick p and q to form the required three segments.

 

// Constraints:

// 3 <= n <= 100
// -1000 <= nums[i] <= 1000



// 🚀 Approach
// Start from the beginning of the array.
// Phase 1 (Increasing): Move forward while the sequence is strictly increasing.
//     If no increase happens (i.e., i == 0) or it reaches to the end (i.e. i == n - 1), return false.
// Phase 2 (Decreasing): Continue while the sequence is strictly decreasing.
//     If the decrease ends at the last element (i == n - 1), return false because we still need the final increase.
// Phase 3 (Increasing again): Continue while the sequence is strictly increasing.
// At the end, check if we reached the last element (i == n - 1).
//     If yes, return true.
//     Otherwise, return false.
// This ensures the array follows the exact increase → decrease → increase pattern.


// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)









class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        // Inc...
        while(i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        if (i == 0 || i == n - 1) return false;

        // Dec...
        while(i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }
        if (i == n - 1) return false;

        // Inc...
        while(i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        
        return (i == n - 1) ? true : false;
    }
};