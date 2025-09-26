// LEETCODE 611. Valid Triangle Number

// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

 

// Example 1:

// Input: nums = [2,2,3,4]
// Output: 3
// Explanation: Valid combinations are: 
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
// Example 2:

// Input: nums = [4,2,3,4]
// Output: 4
 

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 1000


// 🚀 Approach
// Sort the array to simplify triangle inequality checks.
// Fix the third side (nums[k]) from the end.
// Use two pointers (i and j) to find how many pairs (i, j) satisfy nums[i] + nums[j] > nums[k].
// If valid, all elements between i and j form valid triangles with nums[k], so add j - i to the count.
// Move pointers accordingly to explore all combinations.




class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int cnt = 0;
        
        for (int k = n - 1; k >= 2; k--) {
            int i = 0;
            int j = k - 1;
            while(i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    cnt += j - i;
                    j--;
                }
                else i++;
            }
        }
        return cnt;
    }
}