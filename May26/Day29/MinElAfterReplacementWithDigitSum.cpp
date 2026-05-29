// LEETCODE 3300. Minimum Element After Replacement With Digit Sum

// You are given an integer array nums.

// You replace each element in nums with the sum of its digits.

// Return the minimum element in nums after all replacements.

 

// Example 1:

// Input: nums = [10,12,13,14]

// Output: 1

// Explanation:

// nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

// Example 2:

// Input: nums = [1,2,3,4]

// Output: 1

// Explanation:

// nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

// Example 3:

// Input: nums = [999,19,199]

// Output: 10

// Explanation:

// nums becomes [27, 10, 19] after all replacements, with minimum element 10.

 

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 104


// Approach
// Define a helper function digitSum(num) that extracts digits using modulo (% 10) and division (/ 10) until the number becomes zero, accumulating their sum.
// Iterate through the array nums.
// For each number, compute its digit sum using the helper function.
// Keep updating the minimum digit sum encountered.
// Return the minimum at the end.

// Complexity
// Time complexity: O(n * d), d = digit sum for number with d digits
// Space complexity: O(1)



class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while(num > 0) {
            int d = num % 10;
            sum += d;
            num /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int minEl = INT_MAX;
        for (int num : nums) {
            minEl = min(minEl , digitSum(num));
        }
        return minEl;
    }
};