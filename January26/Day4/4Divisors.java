// LEETCODE 1390. Four Divisors

// Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

// Example 1:

// Input: nums = [21,4,7]
// Output: 32
// Explanation: 
// 21 has 4 divisors: 1, 3, 7, 21
// 4 has 3 divisors: 1, 2, 4
// 7 has 2 divisors: 1, 7
// The answer is the sum of divisors of 21 only.
// Example 2:

// Input: nums = [21,21]
// Output: 64
// Example 3:

// Input: nums = [1,2,3,4,5]
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 104
// 1 <= nums[i] <= 105



// 🚀 Approach
// For each number, iterate factors up to √n.
// Count divisors and accumulate their sum.
// Stop early if divisors exceed 4.
// Return sum only if divisor count is exactly 4.
// Accumulate results across all numbers.


// 🕛 Complexity
// Time complexity: O(m * √N)
// m = total numbers in array
// N = maximum number

// Space complexity: O(1)









class Solution {
    private int findSumDivs(int num) {
        int divsCnt = 0;
        int s = 0;

        for (int factor = 1; factor * factor <= num; factor++) {
            if (num % factor == 0) {
                int other = num / factor;

                if (other == factor) {
                    divsCnt++;
                    s += factor;
                } else {
                    divsCnt += 2;
                    s += (factor + other);
                }
            }

            if (divsCnt > 4) return 0;
        }
        return divsCnt == 4 ? s : 0;
    }

    public int sumFourDivisors(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += findSumDivs(num);
        }
        return sum;
    }
}