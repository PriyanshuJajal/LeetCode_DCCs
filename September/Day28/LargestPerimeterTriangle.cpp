// LEETCODE 976. Largest Perimeter Triangle

// Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

 

// Example 1:

// Input: nums = [2,1,2]
// Output: 5
// Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
// Example 2:

// Input: nums = [1,2,1,10]
// Output: 0
// Explanation: 
// You cannot use the side lengths 1, 1, and 2 to form a triangle.
// You cannot use the side lengths 1, 1, and 10 to form a triangle.
// You cannot use the side lengths 1, 2, and 10 to form a triangle.
// As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.
 

// Constraints:

// 3 <= nums.length <= 104
// 1 <= nums[i] <= 106



// 🚀 Approach
// Sort the array in ascending order.
// Iterate from the third-last element to the beginning.
// For each triplet (nums[i], nums[i + 1], nums[i + 2]), check if it satisfies the triangle condition:
    // nums[i] + nums[i+1] > nums[i+2].
// Return the perimeter if valid; otherwise, continue.
// If no valid triangle is found, return 0.




class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums) , end(nums));

        for (int i = n - 3; i >= 0; i--) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2]; 
            }
        }
        return 0;
    }
};