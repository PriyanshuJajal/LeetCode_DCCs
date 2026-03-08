// LEETCODE 1980. Find Unique Binary String

// Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

// Example 1:

// Input: nums = ["01","10"]
// Output: "11"
// Explanation: "11" does not appear in nums. "00" would also be correct.
// Example 2:

// Input: nums = ["00","01"]
// Output: "11"
// Explanation: "11" does not appear in nums. "10" would also be correct.
// Example 3:

// Input: nums = ["111","011","001"]
// Output: "101"
// Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

// Constraints:

// n == nums.length
// 1 <= n <= 16
// nums[i].length == n
// nums[i] is either '0' or '1'.
// All the strings of nums are unique.


// 🚀 Approach
// Let n = nums.size().
// Initialize an empty string res.
// For each index i from 0 to n - 1:
//     Look at the i‑th character of the i‑th string (nums[i][i]).
//     Flip it: if it’s 0, append 1; if it’s 1, append 0.
// Return the constructed string res.

// This ensures that res is different from every string in nums, because at position i, it differs from nums[i].

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(n)









class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";

        for (int i = 0; i < n; i++) {
            char ch = nums[i][i];

            res += (ch == '0') ? "1" : "0";
        }
        return res;
    }
};