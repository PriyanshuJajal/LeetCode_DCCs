// LEETCODE 1018. Binary Prefix Divisible By 5

// You are given a binary array nums (0-indexed).

// We define xi as the number whose binary representation is the subarray nums[0..i] (from most-significant-bit to least-significant-bit).

// For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.
// Return an array of booleans answer where answer[i] is true if xi is divisible by 5.

 

// Example 1:

// Input: nums = [0,1,1]
// Output: [true,false,false]
// Explanation: The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.
// Only the first number is divisible by 5, so answer[0] is true.
// Example 2:

// Input: nums = [1,1,1]
// Output: [false,false,false]
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
 



// 🚀 Approach
// Initialize a variable num = 0 to track the current prefix value modulo 5.
// Iterate through each bit in nums:
//     Left shift num by 1 (equivalent to multiplying by 2).
//     Add the current bit using bitwise OR.
//     Take modulo 5 to keep the value small and only track divisibility.
// Append true to the result if num == 0, otherwise append false.
// Return the result vector res after processing all bits.

// This way, we never store large numbers and only maintain the modulo state.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(n)











class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        vector<bool> res;

        for (int bit : nums) {
            num = ((num << 1) | bit) % 5;
            res.push_back(num == 0);
        }
        return res;
    }
};