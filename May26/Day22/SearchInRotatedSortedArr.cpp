// LEETCODE 33. Search in Rotated Sorted Array

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104


// 🚀 Approach
// Initialize two pointers: l = 0, h = n - 1.
// While l <= h, compute mid = l + (h - l) / 2.
// If nums[mid] == target, return mid.
// Check which half is sorted:
// If nums[l] <= nums[mid], the left half is sorted.
//         If target lies between nums[l] and nums[mid], search left (h = mid - 1).
//         Else, search right (l = mid + 1).
//     Else, the right half is sorted.
//         If target lies between nums[mid] and nums[h], search right (l = mid + 1).
//         Else, search left (h = mid - 1).
// If not found, return -1.

// 🕛 Complexity
// Time complexity: O(logn)
// Space complexity: O(1)


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , h = n - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) h = mid - 1;
                else l = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[h]) l = mid + 1;
                else h = mid - 1;
            }
        }
        return -1;
    }
};