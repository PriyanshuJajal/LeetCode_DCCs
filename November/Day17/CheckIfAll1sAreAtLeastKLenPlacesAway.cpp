// LEETCODE 1437. Check If All 1's Are at Least Length K Places Away


// Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.

 

// Example 1:


// Input: nums = [1,0,0,0,1,0,0,1], k = 2
// Output: true
// Explanation: Each of the 1s are at least 2 places away from each other.
// Example 2:


// Input: nums = [1,0,0,1,0,1], k = 2
// Output: false
// Explanation: The second 1 and third 1 are only one apart from each other.
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= k <= nums.length
// nums[i] is 0 or 1






// 🚀 Approach
// Initialize a counter cnt to k so the first 1 is always valid.
// Traverse the array:
//     If the current element is 0, increment cnt.
//     If it's 1, check if cnt < k. If so, return false (spacing violated).
//     Reset cnt to 0 after a valid 1.
// If the loop completes without violations, return true.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)












class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = k;
        for (int num : nums) {
            if (num == 0) cnt++;
            else {
                if (cnt < k) return false;
                cnt = 0;
            }
        }
        return true;
    }
};