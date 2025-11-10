// LEETCODE 3542. Minimum Operations to Convert All Elements to Zero

// You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become 0.

// In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) and set all occurrences of the minimum non-negative integer in that subarray to 0.

// Return the minimum number of operations required to make all elements in the array 0.

 

// Example 1:

// Input: nums = [0,2]

// Output: 1

// Explanation:

// Select the subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0].
// Thus, the minimum number of operations required is 1.
// Example 2:

// Input: nums = [3,1,2,1]

// Output: 3

// Explanation:

// Select subarray [1,3] (which is [1,2,1]), where the minimum non-negative integer is 1. Setting all occurrences of 1 to 0 results in [3,0,2,0].
// Select subarray [2,2] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [3,0,0,0].
// Select subarray [0,0] (which is [3]), where the minimum non-negative integer is 3. Setting all occurrences of 3 to 0 results in [0,0,0,0].
// Thus, the minimum number of operations required is 3.
// Example 3:

// Input: nums = [1,2,1,2,1,2]

// Output: 4

// Explanation:

// Select subarray [0,5] (which is [1,2,1,2,1,2]), where the minimum non-negative integer is 1. Setting all occurrences of 1 to 0 results in [0,2,0,2,0,2].
// Select subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,2,0,2].
// Select subarray [3,3] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,2].
// Select subarray [5,5] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,0].
// Thus, the minimum number of operations required is 4.
 

// Constraints:

// 1 <= n == nums.length <= 105
// 0 <= nums[i] <= 105




// 🚀 Approach
// Traverse the array from left to right.
// Use a stack to maintain a non-decreasing sequence.
// If the current number is smaller than the top of the stack, pop elements and count operations.
// Push the current number if it's positive and either the stack is empty or it's greater than the top.
// After traversal, pop remaining stack elements and count them as operations.


// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(n)









class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        stack<int> st;
        
        for (int num : nums) {
            while(!st.empty() && st.top() > num) {
                cnt++;
                st.pop();
            }
            if (num > 0 && (st.empty() || st.top() < num)) st.push(num);
        }
        while(!st.empty()) {
            st.pop();
            cnt++;
        }
        return cnt;
    }
};