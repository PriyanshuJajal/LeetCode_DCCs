// LEETCODE 3507. Minimum Pair Removal to Sort Array I

// Given an array nums, you can perform the following operation any number of times:

// Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
// Replace the pair with their sum.
// Return the minimum number of operations needed to make the array non-decreasing.

// An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

// Example 1:

// Input: nums = [5,2,3,1]

// Output: 2

// Explanation:

// The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
// The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
// The array nums became non-decreasing in two operations.

// Example 2:

// Input: nums = [1,2,2]

// Output: 0

// Explanation:

// The array nums is already sorted.

 

// Constraints:

// 1 <= nums.length <= 50
// -1000 <= nums[i] <= 1000


// 🚀 Approach
// Find the minimum adjacent pair:
//     Iterate through the array and compute the sum of each adjacent pair.
//     Track the position of the pair with the smallest sum.
// Merge the pair:
//     Add the second element of the pair to the first.
//     Remove the second element from the array.
// Repeat until sorted:
//     Continue merging the minimum adjacent pair until the entire array is sorted in non-decreasing order.
//     Count the number of operations performed.

// 🕛 Complexity
// Time complexity: O(n²)
// Space complexity: O(1)









class Solution {
public:
    int minPair(vector<int>& nums) {
        int minSum = 1e9;
        int pos = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + nums[i + 1] < minSum) {
                minSum = nums[i] + nums[i + 1];
                pos = i;
            }
        }
        return pos;
    }

    void merge(vector<int>& nums , int pos) {
        nums[pos] += nums[pos + 1];
        nums.erase(begin(nums) + pos + 1);
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!is_sorted(begin(nums) , end(nums))) {
            merge(nums , minPair(nums));
            ops++;
        }
        return ops;
    }
};