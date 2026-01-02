// LEETCODE 961. N-Repeated Element in Size 2N Array

// You are given an integer array nums with the following properties:

// nums.length == 2 * n.
// nums contains n + 1 unique elements.
// Exactly one element of nums is repeated n times.
// Return the element that is repeated n times.

 

// Example 1:

// Input: nums = [1,2,3,3]
// Output: 3
// Example 2:

// Input: nums = [2,1,2,5,3,2]
// Output: 2
// Example 3:

// Input: nums = [5,1,5,2,5,3,5,4]
// Output: 5
 

// Constraints:

// 2 <= n <= 5000
// nums.length == 2 * n
// 0 <= nums[i] <= 104
// nums contains n + 1 unique elements and one of them is repeated exactly n times.





// 🚀 Approach
// Iterate through the nums while checking pairs of consecutive or near-consecutive elements.
// If any element is equal to its immediate neighbor (nums[i] == nums[i + 1]) or the element two steps ahead (nums[i] == nums[i + 2]), that element must be the repeated one.
// If no match is found in the loop, the repeated element will be the last element in the array (since the guarantee ensures it must exist).

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)









class Solution {
    public int repeatedNTimes(int[] nums) {
        for (int i = 0; i < nums.length - 2; i++) {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) {
                return nums[i];
            }
        }
        return nums[nums.length - 1];
    }
}


// Map Approach...
import java.util.HashMap;

class Solution {
    public int repeatedNTimes(int[] nums) {
        int n = nums.length / 2;
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (int key : map.keySet()) {
            if (map.get(key) == n) {
                return key;
            }
        }
        return -1; 
    }
}